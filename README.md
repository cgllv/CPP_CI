# CPP_CI

### 1. add submodule
> git clone -b v1.9.6 https://github.com/catchorg/Catch2.git ./third_party/Catch

> git clone -b v0.13.0 https://github.com/gabime/spdlog.git ./third_party/spdlog

### 2. build command
> cmake -H. -Bbuild -DCMAKE_BUILD_TYPE=Release

> cd build  
> cmake --build . --config Release