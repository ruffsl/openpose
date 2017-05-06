FROM bvlc/caffe:gpu

# TODO: audit build/run dependencies
RUN apt-get update && apt-get install -y \
      build-essential \
      cmake \
      git \
      libatlas-base-dev \
      libatlas-dev \
      libboost-all-dev \
      libgflags-dev \
      libgoogle-glog-dev \
      libhdf5-dev \
      libleveldb-dev \
      liblmdb-dev \
      libopencv-dev \
      libprotobuf-dev \
      protobuf-compiler \
      python-dev \
      python-numpy \
      python-pip \
      python-setuptools \
      python-scipy \
      wget \
    && rm -rf /var/lib/apt/lists/*

# TODO: avoid moving around caffe source build and relinking
WORKDIR $CAFFE_ROOT/build
RUN make install

ENV OPENPOSE_ROOT=/opt/openpose
WORKDIR $OPENPOSE_ROOT

# TODO: Add ARG for choosing a release
# RUN git clone https://github.com/CMU-Perceptual-Computing-Lab/openpose.git .
COPY . $OPENPOSE_ROOT

# TODO: Fix all the cmake issues for transparency
RUN mkdir build && cd build && \
    cmake -DUSE_CUDNN=1 -DUSE_CAFFE=1 -DCPU_ONLY=0 .. && \
    make -j1 #-j"$(nproc)"
