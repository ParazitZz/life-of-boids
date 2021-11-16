FROM conanio/gcc9

MAINTAINER arthurviens

COPY conanfile.txt ./

RUN sudo apt update && sudo apt install -y libgtk2.0-dev libgl1-mesa-dev \
    && conan profile new default --detect \
    && conan profile update settings.compiler.libcxx=libstdc++11 default \
    && mkdir buildGCC \
    && cd buildGCC \
    && conan install .. --build=missing \
    && conan remove "*" -s -b -f \
    && sudo rm -rf /var/lib/apt/lists/* \
    && rm -fr ~/buildGCC