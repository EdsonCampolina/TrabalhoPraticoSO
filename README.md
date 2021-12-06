# TrabalhoPraticoSO

Nesse trabalho desenvolveremos um banco de dados de chave-valor

## Lista de tarefas
- [x] CRUD;
- [x] Escrita em arquivo dos dados;
- [x] Estra do arquivo de log;
- [x] Implementar threads (Inserção de dados no banco, escrita do arquivo de log, escrita do arquivo de dados do banco);
- [x] Escrita dos arquivos de teste das funções do banco (input.txt);
- [x] Criar arquivo output.txt com a saída esperada pelos comandos contidos no input.txt (para checkar com o arquivo output2.txt com a saída da versão atual do programa);
- [x] Escrita do Makefile;
- [x] Implementar tabela HASH (A tabela que será armazenada no arquivo) [Deixar por último];
- [x] Implementar comando list


## Execução

Para compilar e rodar o código em um ambiente Linux:

```make clean && make all```

# Exemplos de comandos

```./simpledb --insert=123,abcde```

```./simpledb --update=13,5,ccc```

```./simpledb --remove=14```

```./simpledb --search=6```

```./simpledb --list="key>3"```

# Teste

Para rodar o caso de teste 0:

```bash utils/test/0/input.txt```

Para comparar o banco de dados com o arquivo de referência do teste 0:

```diff bd/bd.txt utils/test/0/output.txt```

Para salvar o valor de referência para o caso de teste 0 como output.txt:

```cp bd/bd.txt utils/test/0/ && mv utils/test/0/bd.txt utils/test/0/output.txt```

# Reiniciar

Para reiniciar o banco de dados:

```cp  utils/restart/logs.txt log/ && cp  utils/restart/data.txt cruddbmsData/ && cp  utils/restart/bd.txt bd/```