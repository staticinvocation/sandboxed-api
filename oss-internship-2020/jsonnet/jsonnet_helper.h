// Copyright 2020 Google LLC
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

#include "jsonnet/cmd/utils.h"

extern "C" {
#include <libjsonnet.h>
}

extern "C" struct JsonnetVm* c_jsonnet_make(void);

extern "C" void c_jsonnet_destroy(struct JsonnetVm* vm);

extern "C" char* c_jsonnet_evaluate_snippet(struct JsonnetVm* vm, const char* filename, char* snippet, int* error);

extern "C" char* c_read_input(bool filename_is_code, const char* filename);

extern "C" void c_free_input(char* input);

extern "C" bool c_write_output_file(const char* output, const char* output_file);

extern "C" char* c_jsonnet_realloc(JsonnetVm* vm, char* str, size_t sz);