FROM ubuntu

RUN apt-get update
RUN apt-get install -y wget
RUN apt-get install -y tar
RUN apt-get install -y xorriso
RUN apt-get install -y grub-pc-bin
RUN apt-get install -y grub-common

# x86_64 -> https://newos.org/toolchains/x86_64-elf-7.5.0-Linux-x86_64.tar.xz 

RUN cd $HOME && wget --load-cookies /tmp/cookies.txt "https://docs.google.com/uc?export=download&confirm=$(wget --quiet --save-cookies /tmp/cookies.txt --keep-session-cookies --no-check-certificate 'https://docs.google.com/uc?export=download&id=0Bw6lG3Ej2746STJaM2dNbC05elE' -O- | sed -rn 's/.*confirm=([0-9A-Za-z_]+).*/\1\n/p')&id=0Bw6lG3Ej2746STJaM2dNbC05elE" -O toolchain.tar.gz && rm -rf /tmp/cookies.txt
RUN cd $HOME && tar -xzvf toolchain.tar.gz

ENV PATH="/root/opt/cross/bin:${PATH}"

RUN apt-get install make
RUN apt-get install nasm

VOLUME /root/env
WORKDIR /root/env