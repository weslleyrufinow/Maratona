#!/bin/bash

#Diretorio onde estao as inputs
dirInputs=$(pwd)"/Teste/InputsTest/"

#Esse garante que a cada rodada, os resultados dos testes sejam feitos do zero
rm "GBAll.txt"

# Loop pelos arquivos do diretório
for input in "$dirInputs"*
do
    ./B2020.out < "$input"
    wait
done

diff GBAll.txt "$(pwd)/Teste/allOutputs.txt" -s -q