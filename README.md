# TrabalhoPraticoSO

Nesse trabalho desenvolveremos um banco de dados de chave-valor

## Lista de tarefas
- [x] CRUD;
- [x] Escrita em arquivo dos dados;
- [x] Estra do arquivo de log;
- [ ] Implementar threads (Inserção de dados no banco, escrita do arquivo de log, escrita do arquivo de dados do banco);
- [ ] Escrita dos arquivos de teste das funções do banco (input.txt);
- [ ] Criar arquivo output.txt com a saída esperada pelos comandos contidos no input.txt (para checkar com o arquivo output2.txt com a saída da versão atual do programa);
- [ ] Escrita do Makefile;
- [ ] Implementar tabela HASH (A tabela que será armazenada no arquivo) [Deixar por último];
- [ ] Implementar comando list


## Execução

Para compilar e rodar o código em um ambiente Linux:

```make main && ./main```

Para cada versão do código executar os comandos abaixo para validação:
cat input.txt |  ./simpldb  > output2.txt
diff output.txt output2.txt 

# Exemplos de comandos

```./simpledb --insert=123,abcde```

```./simpledb --update=13,5,ccc```

```./simpledb --remove=14```

```./simpledb --search=6```