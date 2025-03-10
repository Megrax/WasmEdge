// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2022 Second State INC

#pragma once

#include "host/wasi/environ.h"
#include "runtime/importobj.h"

namespace WasmEdge {
namespace Host {

class WasiModule : public Runtime::ImportObject {
public:
  WasiModule();

  WASI::Environ &getEnv() { return Env; }

private:
  WASI::Environ Env;
};

} // namespace Host
} // namespace WasmEdge
