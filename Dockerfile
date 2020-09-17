FROM frolvlad/alpine-gcc as build
COPY ./test.c /root/test.c
RUN gcc -std=c11 -O3 -Wall -o /root/output /root/test.c

FROM alpine as final
COPY --from=build /root/output /root
