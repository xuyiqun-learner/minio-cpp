# MinIO C++ Client SDK for Amazon S3 Compatible Cloud Storage [![Slack](https://slack.min.io/slack?type=svg)](https://slack.min.io) [![Sourcegraph](https://sourcegraph.com/github.com/minio/minio-cpp/-/badge.svg)](https://sourcegraph.com/github.com/minio/minio-cpp?badge) [![Apache V2 License](https://img.shields.io/badge/license-Apache%20V2-blue.svg)](https://github.com/minio/minio-cpp/blob/master/LICENSE)

MinIO C++ SDK is Simple Storage Service (aka S3) client to perform bucket and object operations to any Amazon S3 compatible object storage service.

For a complete list of APIs and examples, please take a look at the [MinIO C++ Client API Reference](https://minio-cpp.min.io/)

## Build requirements
* A working C++ development environment supporting C++17 standards.
* CMake 3.10 or higher.
* [vcpkg](https://vcpkg.io/en/index.html).

## Install from `vcpkg`
```
vcpkg install minio-cpp
```

## cross-compile Building source
```bash
$ ./vcpkg-master/vcpkg --triplet=arm64-linux-release integrate install
$ cmake -B ./build_arm64  -DVCPKG_TARGET_TRIPLET=arm64-linux-release -DCMAKE_TOOLCHAIN_FILE=./vcpkg-master/scripts/buildsystems/vcpkg.cmake-DCMAKE_TOOLCHAIN_FILE=./vcpkg-master/scripts/buildsystems/vcpkg.cmake
$ cmake --build ./build

## License
This SDK is distributed under the [Apache License, Version 2.0](https://www.apache.org/licenses/LICENSE-2.0), see [LICENSE](https://github.com/minio/minio-cpp/blob/master/LICENSE) for more information.
