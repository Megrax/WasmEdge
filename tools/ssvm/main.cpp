#include "vm/result.h"
#include "vm/vm.h"

int main(int Argc, char *Argv[]) {
  std::string InputPath("ethereum/erc20.wasm");
  SSVM::VM::Environment Env;
  SSVM::VM::VM VM(Env);
  SSVM::Result Result;
  VM.setPath(InputPath);
  VM.execute();
  Result = VM.getResult();
  return 0;
}
