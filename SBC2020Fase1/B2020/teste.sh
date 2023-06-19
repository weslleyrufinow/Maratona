#!/bin/bash

#diff GBAll.txt "$(pwd)/IO/allOutputs.txt"

#Diretorio onde estao as inputs
dirInputs=$(pwd)"/IO/Inputs/"

#Esse garante que a cada rodada, os resultados dos testes sejam feitos do zero
rm "GBAll.txt"

# Loop pelos arquivos do diretório
for input in "$dirInputs"*
do
    echo $input 
    ./alex < "$input"
    wait
done
diff GBAll.txt "$(pwd)/IO/allOutputs.txt" -s -q