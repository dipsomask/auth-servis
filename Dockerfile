FROM drogonframework/drogon:latest

RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    g++ \
    cmake \
    git \
    wget \
    unzip \
    libjsoncpp-dev \
    pkg-config \
    libpqxx-dev \
    openssl \
    libssl-dev \
    uuid-dev \
    zlib1g-dev \
    libmariadb3 \
    libyaml-cpp0.8 \
    postgresql-all


ENV DROGON_PATH /opt/drogon
RUN git clone https://github.com/drogonframework/drogon $DROGON_PATH
WORKDIR $DROGON_PATH
RUN git submodule update --init
RUN mkdir build
WORKDIR $DROGON_PATH/build
RUN cmake .. && make && make install


COPY test-db-servis-0.1.1-Linux.deb /root
COPY servisCfg.json /usr/src
COPY config.example.nossl.json /usr/src


WORKDIR /root
RUN dpkg -i test-db-servis-0.1.1-Linux.deb
RUN chmod +x /usr/bin/test-db-servis

CMD [ "bash" ]
