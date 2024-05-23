FROM gcc:latest

WORKDIR /usr/src/project1

COPY ./src/ .

RUN g++ -o run ./BloomFilter.cpp ./CheckUrlCommand.cpp ./InsertUrlCommand.cpp ./HashOne.cpp ./HashTwo.cpp ./InputValidation.cpp ./ServerSocket.cpp

CMD ["./run"]

EXPOSE 5555