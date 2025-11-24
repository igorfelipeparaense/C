#!/bin/bash

# Verificando se um argumento foi passado
if [$# -eq o]; then
    echo "Por favor, forneça um nome de arquivo como argumento."
    exit 1
fi

name2="0001"

# Realiza alguma ação com o arquivo (imprimir neste caso)
gcc -o $name2 $1
./name2
rm $name2

# Deixa mais rápido a compilação e execução
# Exclui automaticamente, não perder tempo
# Para executar no terminal rode ./exec.sh arquivo.c