# Build libopenthread for QCA402X

In a Bash terminal, follow these instructions to install the GNU toolchain and other dependencies.
```bash
$ cd <path-to-ot-qca402x>
$ ./script/bootstrap
```

In a Bash terminal, follow these instructions to build the libopenthread.
```bash
$ cd <path-to-ot-qca402x>
$ git submodule update --init --recursive .
$ ./script/build
```

- build output lib in "build/CDB4024/lib"
- configure file is "include/openthread-core-qca4024-config.h"
- this build use soft mbedTLS
- default build is debug version
- openthread version is "b6ac79f61"