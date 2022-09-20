# ED-2 Descrição do trabalho
Dado um texto com N caracteres, encontrar todas as ocorrências de uma string Q a ser consultada (query string)  juntamente com o contexto C. O contexto é o número de caracteres adicionais de cada lado que devem ser exibidos quando o termo da busca for encontrado. Deve-se fazer um pré processamento para permitir uma busca rápida de substrings usando array de sufixos.

Exemplo: Dado o texto N= "in/tale.txt", a query Q = "better thing" e o contexto C = 15, o resultado esperado é:
$ ./a.out -c in/abra.txt 15 "better thing"
t is a far far better thing that i do than
 some sense of better things else forgotte
was capable of better things mr carton ent
