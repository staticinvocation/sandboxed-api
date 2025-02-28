// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef SANDBOXED_API_EXAMPLES_STRINGOP_SANDBOX_H_
#define SANDBOXED_API_EXAMPLES_STRINGOP_SANDBOX_H_

#include <linux/audit.h>
#include <sys/syscall.h>

#include "sandboxed_api/examples/stringop/stringop-sapi.sapi.h"
#include "sandboxed_api/sandbox2/policy.h"
#include "sandboxed_api/sandbox2/policybuilder.h"

class StringopSapiSandbox : public StringopSandbox {
 public:
  std::unique_ptr<sandbox2::Policy> ModifyPolicy(
      sandbox2::PolicyBuilder*) override {
    // Return a new policy.
    return sandbox2::PolicyBuilder()
        .AllowRead()
        .AllowWrite()
        .AllowOpen()
        .AllowSystemMalloc()
        .AllowHandleSignals()
        .AllowExit()
        .AllowStat()
        .AllowTime()
        .AllowSyscalls({
            __NR_recvmsg,
            __NR_sendmsg,
            __NR_lseek,
            __NR_nanosleep,
            __NR_futex,
            __NR_gettid,
            __NR_close,
        })
        .AddFile("/etc/localtime")
        .BuildOrDie();
  }
};

#endif  // SANDBOXED_API_EXAMPLES_STRINGOP_SANDBOX_H_
