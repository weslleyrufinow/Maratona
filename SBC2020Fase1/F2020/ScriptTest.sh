#!/bin/bash

#Diretorio onde estao as inputs
dirInputs=$(pwd)"/Teste/InputsTest/"

#Esse garante que a cada rodada, os resultados dos testes sejam feitos do zero
rm "GBAll.txt"

# Loop pelos arquivos do diretório
for input in "$dirInputs"*
do
    #echo $input
    ./F2020 < "$input"
    break
    #echo
    wait
done

diff GBAll.txt "$(pwd)/Teste/allOutputs.txt" -s -q