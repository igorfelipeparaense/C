# --- ESTÁGIO 1: COMPILAÇÃO ---
# Usa uma imagem base que já vem com o compilador GCC instalado
FROM gcc:12.3-buster AS build
WORKDIR /app
COPY . .
# Compila o código: "gcc main.c -o myapp" cria um executável chamado "myapp"
RUN gcc main.c -o myapp

# --- ESTÁGIO 2: EXECUÇÃO (Runtime) ---
# Usa uma imagem base mínima, como o Alpine, para o ambiente de execução
# Se a sua aplicação C depender de bibliotecas externas, talvez precise usar uma imagem como 'debian:buster-slim' e instalar as libs necessárias aqui.
FROM alpine:latest AS runtime
WORKDIR /app
# Copia apenas o executável do estágio de compilação
COPY --from=build /app/myapp .
# Define o comando para executar a aplicação quando o contêiner iniciar
CMD ["./myapp"]