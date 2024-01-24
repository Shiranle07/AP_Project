FROM gcc:latest

WORKDIR /usr/src/project1

COPY ./src/ .

RUN g++ -o run ./App.cpp ./BloomFilter.cpp ./CheckUrlCommand.cpp ./InsertUrlCommand.cpp ./HashOne.cpp ./HashTwo.cpp ./InputValidation.cpp ./main.cpp

CMD ["./run"]