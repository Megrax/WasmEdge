# Install and uninstall WasmEdge

## Quick install

The easiest way to install WasmEdge is to run the following command. Your system should have `git` and `curl` as prerequisites.

```bash
$ curl -sSf https://raw.githubusercontent.com/WasmEdge/WasmEdge/master/utils/install.sh | bash
```

If you would like to install WasmEdge with its [Tensorflow and image processing extensions](https://www.secondstate.io/articles/wasi-tensorflow/), please run the following command. It will attempt to install Tensorflow and image shared libraries on your system.

```bash
$ curl -sSf https://raw.githubusercontent.com/WasmEdge/WasmEdge/master/utils/install.sh | bash -s -- -e all
```

Run the following command to make the installed binary available in the current session.

```bash
$ source $HOME/.wasmedge/env
```

**That's it!** You can now use WasmEdge from the CLI, or launch it from an application. To update WasmEdge to a new release, just re-run the above command to write over the old files.

## Install for all users

By default, WasmEdge is installed in the `$HOME/.wasmedge` directory. You can install it into a system directory, such as `/usr/local` to make it available to all users. To specify an install directory, you can run the `install.sh` script with the `-p` flag. You will need to run the following commands as the `root` user or `sudo` since they write into system directories.

```bash
$ curl -sSf https://raw.githubusercontent.com/WasmEdge/WasmEdge/master/utils/install.sh | bash -s -- -p /usr/local
```

Or, with all extensions

```bash
$ curl -sSf https://raw.githubusercontent.com/WasmEdge/WasmEdge/master/utils/install.sh | bash -s -- -e all -p /usr/local
```

## Install a specific version of WasmEdge

You could install specific versions of WasmEdge, including pre-releases or old releases by passing the `-v` argument to the install script. Here is an example.

```bash
$ curl -sSf https://raw.githubusercontent.com/WasmEdge/WasmEdge/master/utils/install.sh | bash -s -- -e all -v 0.9.0
```

If you are interested in the latest builds from the `HEAD` of the `master` branch, which is basically WasmEdge's nightly builds, you can download the release package directly from our Github Action's CI artifact. [Here is an example](https://github.com/WasmEdge/WasmEdge/actions/runs/1521549504#artifacts).

## What's installed

After installation, you have the following directories and files. Here we assume that you installed into the `$HOME/.wasmedge` directory. You could also change it to `/usr/local` if you did a system-wide install.

* The `$HOME/.wasmedge/bin` directory contains the WasmEdge Runtime CLI executable files. You can copy and move them around on your file system.
  * The `wasmedge` tool is the standard WasmEdge runtime. You can use it from the CLI. `wasmedge --dir .:. app.wasm`
  * The `wasmedgec` tool is the AOT compiler to compile a `wasm` file into a native `so` file. `wasmedgec app.wasm app.so` The `wasmedge` can then execute the `so` file. `wasmedge --dir .:. app.so`
  * The `wasmedge-tensorflow`, `wasmedge-tensorflow-lite` tools are runtimes that support the WasmEdge tensorflow SDK.
* The `$HOME/.wasmedge/lib` directory contains WasmEdge shared libraries, as well as dependency libraries. They are useful for WasmEdge SDKs to launch WasmEdge programs and functions from host applications.
* The `$HOME/.wasmedge/include` directory contains the WasmEdge header files. They are useful for WasmEdge SDKs.

## Uninstall

To uninstall WasmEdge, you can run the following command.

```bash
$ bash <(curl -sSf https://raw.githubusercontent.com/WasmEdge/WasmEdge/master/utils/uninstall.sh)
```

If `wasmedge` binary is not in `PATH` and it wasn't installed in the default `$HOME/.wasmedge` folder, then you must provide the installation path.

```bash
$ bash <(curl -sSf https://raw.githubusercontent.com/WasmEdge/WasmEdge/master/utils/uninstall.sh) -p /path/to/parent/folder
```

If you wish to uninstall uninteractively, you can pass in the `--quick` or `-q` flag.

```bash
$ bash <(curl -sSf https://raw.githubusercontent.com/WasmEdge/WasmEdge/master/utils/uninstall.sh) -q
```

> If a parent folder of the `wasmedge` binary contains `.wasmedge`, the folder will be considered for removal. For example, the script removes the default `$HOME/.wasmedge` folder altogether.

## Install WasmEdge for Node.js

WasmEdge can run [WebAssembly functions emebedded in Node.js](https://www.secondstate.io/articles/getting-started-with-rust-function/) applications. To install the WasmEdge module in your Node.js environment is easy. Just use the `npm` tool.

```bash
$ npm install -g wasmedge-core # Append --unsafe-perm if permission denied
```

To install WasmEdge with [Tensorflow and other extensions](https://www.secondstate.io/articles/wasi-tensorflow/).

```bash
$ npm install -g wasmedge-extensions # Append --unsafe-perm if permission denied
```

The [Second State Functions](https://www.secondstate.io/faas/) is a WasmEdge-based FaaS service build on Node.js.
