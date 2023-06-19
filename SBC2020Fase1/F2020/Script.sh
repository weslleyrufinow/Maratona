#!/bin/bash

#Diretorio onde estao as inputs
dirInputs=$(pwd)"/IO/Inputs/"

#Esse garante que a cada rodada, os resultados dos testes sejam feitos do zero
rm "GBAll.txt"

# Loop pelos arquivos do diretório
for input in "$dirInputs"*
do
    #echo $input 
    ./F2020 < "$input"
    #echo
    wait
done
diff GBAll.txt "$(pwd)/IO/allOutputs.txt" -s -q
