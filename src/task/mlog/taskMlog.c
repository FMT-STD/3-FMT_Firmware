/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include <firmament.h>
#include <string.h>
#include <stdio.h>

#include "module/file_manager/file_manager.h"
#include "module/task_manager/task_manager.h"
#include "module/log/mlog.h"

#define TAG "Mlog"

/* Event definitions */
#define EVENT_MLOG_UPDATE (1 << 0)

/* Global variables */
static struct rt_event _mlog_event;
static const struct dfs_mount_tbl mnt_table[] = {{"sd0", "/", "elm", 0, NULL}, {NULL}};

/* Mlog update callback */
static void mlog_update_cb(void) { rt_event_send(&_mlog_event, EVENT_MLOG_UPDATE); }

/* Mlog task entry function */
void task_mlog_entry(void* parameter) {
  rt_err_t rt_err;
  rt_uint32_t recv_set = 0;
  rt_uint32_t wait_set = EVENT_MLOG_UPDATE;

  mlog_register_callback(MLOG_CB_UPDATE, mlog_update_cb);

  while (1) {
    /* wait event happen */
    rt_err = rt_event_recv(&_mlog_event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, 20, &recv_set);

    if (rt_err == RT_EOK) {
      if (recv_set & EVENT_MLOG_UPDATE) {
        mlog_async_output();
      }
    } else if (rt_err == -RT_ETIMEOUT) {
      /* if timeout, check if there are log data need to send */
      mlog_async_output();
    } else {
      /* some other error happen */
    }
  }
}

/* Mlog task initialization */
fmt_err_t task_mlog_init(void) {
  /* create mlog event */
  if (rt_event_init(&_mlog_event, "mlog", RT_IPC_FLAG_FIFO) != RT_EOK) {
    console_printf("mlog event create fail\n");
    return FMT_ERROR;
  }

  /* init binary log */
  mlog_init();

  return FMT_EOK;
}

fmt_err_t logger_start_mlog(char* path) {
  char log_name[100];
  char file_name[50];
  static uint8_t mlog_id = 0;

  if (path) {
    /* if a valid path is provided, use it for mlog */
    return mlog_start(path);
  }

  if (current_log_session(log_name) != FMT_EOK) {
    console_printf("no available log session\n");
    return FMT_ERROR;
  }
  sprintf(file_name, "/mlog%d.bin", ++mlog_id);
  strcat(log_name, file_name);

  return mlog_start(log_name);
}

void logger_stop_mlog(void) {
  mlog_stop();
}

void get_working_log_session(char* path) {
  current_log_session(path);
}

TASK_EXPORT __fmt_task_desc = {
    .name = "mlog",
    .init = task_mlog_init,
    .entry = task_mlog_entry,
    .priority = LOGGER_THREAD_PRIORITY,
    .auto_start = true,
    .stack_size = 2048,
    .param = NULL,
    .dependency = NULL,
    // .dependency = (char*[]) { "vehicle", NULL }
};