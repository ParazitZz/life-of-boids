FROM conanio/clang10

MAINTAINER arthurviens

COPY conanfile.txt ./

RUN sudo apt update && sudo apt install -y libgtk2.0-dev libgl1-mesa-dev \
    && conan profile new default --detect \
    && conan profile update settings.build_type=Debug default \
    && conan profile update settings.compiler.libcxx=libstdc++11 default \
    && mkdir buildCLANG \
    && cd buildCLANG \
    && conan install .. --build=missing \
    && cd .. && rm -rf buildCLANG \
    && conan profile update settings.build_type=Release default \
    && conan profile update settings.compiler.libcxx=libstdc++11 default \
    && mkdir buildCLANG \
    && cd buildCLANG \
    && conan install .. --build=missing \
    && conan remove "*" -s -b -f \
    && sudo rm -rf /var/lib/apt/lists/* \
    && rm -fr ~/buildCLANG