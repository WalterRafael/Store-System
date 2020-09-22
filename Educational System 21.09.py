# mostrando menu principal
def menu_principal():
    print('Escolha a opção: \n'
          '1 - Cadastrar \n'
          '2 - Listar \n'
          '3 - Alterar \n'
          '4 - Excluir \n'
          '5 - Realizar Cópia do arquivo \n'
          '0 - Sair \n'
          'Digite a opção escolhida: ')
    return input()



# funcao menu principal
def opcoes_princial():
    while True:
        opcao = menu_principal()
        if opcao == 1:
            menu_cadastro()
        elif opcao == 2:
            menu_listar()
        elif opcao == 3:
            menu_alterar()
        elif opcao == 4:
            menu_excluir()
        elif opcao == 5:
            menu_copiar()
        else:
            print('Programa finalizado!')
            break

# mostrando menu cadastro 
def menu_cadastro():
    print("Escolha a opção: \n"
          "1 - Cadastrar Aluno \n"
          "2 - Cadastrar Professor\n"
          "3 - Cadastrar Disciplina\n"
          "4 - Cadastrar Curso\n"
          "0 - Voltar \n"
          "Digite a opção escolhida: ")



# funcao menu cadastro
def opcoes_cadastro():
    while True:
        opcao = menu_cadastro()
        if opcao == 1:
            cadastro_aluno()
        elif opcao == 2:
            cadastro_professor()
        elif opcao == 3:
            cadastro_disciplina()
        elif opcao == 4:
            cadastro_curso()
        else:
            print('Programa finalizado!')
            break

# mostrando menu listar 
def menu_listar():
    print("Escolha a opção: \n"
          "1 - Listar Alunos \n"
          "2 - Listar Professores\n"
          "3 - Listar Disciplinas\n"
          "4 - Listar Cursos\n"
          "0 - Voltar \n"
          "Digite a opção escolhida: ")



# funcao menu listar
def opcoes_listar():
    while True:
        opcao = menu_listar()
        if opcao == 1:
            listar_aluno()
        elif opcao == 2:
            listar_professor()
        elif opcao == 3:
            listar_disciplina()
        elif opcao == 4:
            listar_curso()
        else:
            print('Programa finalizado!')
            break


# mostrando menu alterar 
def menu_alterar():
    print("Escolha a opção: \n"
          "1 - Alterar dados Alunos \n"
          "2 - Alterar dados Professors\n"
          "3 - Alterar dados Disciplinas\n"
          "4 - Alterar Cursos\n"
          "0 - Voltar \n"
          "Digite a opção escolhida: ")



# funcao menu alterar
def opcoes_alterar():
    while True:
        opcao = menu_alterar()
        if opcao == 1:
            nome_a = input('Insira o nome do aluno que deseja alterar: ').title()
            alterar_aluno(nome_a)
        elif opcao == 2:
            nome_p = input('Insira o nome do professor que deseja alterar: ').title()
            alterar_professor(nome_p)
        elif opcao == 3:
            nome_d = input('Insira o nome da disciplina que deseja alterar: ').title()
            alterar_disciplina(nome_d)
        elif opcao == 4:
            nome_c = input('Insira o nome do curso que deseja alterar: ').title()
            alterar_curso(nome_c)
        else:
            print('Programa finalizado!')
            break


# mostrando menu excluir 
def menu_excluir():
    print("Escolha a opção: \n"
          "1 - Excluir dados Alunos \n"
          "2 - Excluir dados Professors\n"
          "3 - Excluir dados Disciplinas\n"
          "4 - Excluir Cursos\n"
          "0 - Voltar \n"
          "Digite a opção escolhida: ")



# funcao menu excluir
def opcoes_excluir():
    while True:
        opcao = menu_excluir()
        if opcao == 1:
            nome_a = input('Insira o nome do aluno que deseja excluir: ').title()
            excluir_aluno(nome_a)
        elif opcao == 2:
            nome_p = input('Insira o nome do professor que deseja excluir: ').title()
            excluir_professor(nome_p)
        elif opcao == 3:
            nome_d = input('Insira o nome da disciplina que deseja excluir: ').title()
            excluir_disciplina(nome_d)
        elif opcao == 4:
            nome_c = input('Insira o nome do curso que deseja excluir: ').title()
            excluir_curso(nome_c)
        else:
            print('Programa finalizado!')
            break


# mostrando menu copiar 
def menu_copiar():
    print("Escolha a opção: \n"
          "1 - Backup dados Alunos \n"
          "2 - Backup dados Professors\n"
          "3 - Backup dados Disciplinas\n"
          "4 - Backup Cursos\n"
          "0 - Voltar \n"
          "Digite a opção escolhida: ")


# funcao menu copiar
def opcoes_copiar():
    while True:
        opcao = menu_copiar()
        if opcao == 1:
            print("Backup realizado!")
            copiar_aluno()
        elif opcao == 2:
            print("Backup realizado!")
            copiar_professor()
        elif opcao == 3:
            print("Backup realizado!")
            copiar_disciplina()
        elif opcao == 4:
            print("Backup realizado!")
            copiar_curso()
        else:
            print('Programa finalizado!')
            break



# funcao cadastro aluno
def cadastro_aluno():
    try:
        arquivo = open('Dados_Alunos.txt', 'a')
        nome_a = input('Nome completo: ').title()
        idade_a = input('Idade: ')
        matricula_a = (input('Matrícula: '))
        cpf_a = input('CPF: ')
        curso_a = input('Curso matriculado: ')
        cod_curso = input('Código do curso: ')
        arquivo.write('Nome: ' + nome_a + '\n' + 'Idade: '+ idade_a + '\n' + 'Matrícula: ' + matricula_a + '\n' +
                      'CPF: ' + cpf_a + '\n' + 'Cursando: ' + curso_a + '\n' + 'Código curso: ' + cod_curso + '\n')
        arquivo.close()
        print("Aluno cadastrado com sucesso!")
    except IOError as error:
        print('Erro', error)

# funcao cadastro professor
def cadastro_professor():
    try:
        arquivo = open('Dados_Prof.txt', 'a')
        cod_prof = input('Código do professor: ')
        nome_p = input('Nome completo: ').title()
        idade_p = input('Idade: ')
        cpf_p = input('CPF: ')
        curso_p = input('Curso matriculado: ')
        salario_p = float(input('Salário: '))
        cod_curso = input('Código do curso: ')
        cod_disc = input('Código da disciplina: ')
        arquivo.write('Código: ' + cod_prof + 'Nome: ' + nome_a + '\n' + 'Idade: ' + idade_a + '\n' + 'CPF: ' + cpf_p +
                      '\n' + 'Curso: ' + curso_p + '\n' + 'Cód. curso: ' + cod_curso + '\n' + 'Cód. Disciplina: ' + cod_disc + '\n')
        arquivo.close()
        print("Professor cadastrado com sucesso!")
    except IOError as error:
        print('Erro', error)

# funcao cadastro Disciplina
def cadastro_disciplina():
    try:
        arquivo = open('Dados_Disc.txt', 'a')
        cod_disc = input('Código da disciplina: ')
        nome_d = input('Nome: ').title()
        req_d = input('Pré-requisitos: ')
        cargah_d = int(input('Carga horária: '))
        fase_d = input('Fase: ')
        cod_curso = input('Código do curso: ')
        arquivo.write('Código: ' + cod_disc + 'Nome: ' + nome_d + '\n' + 'Pré-requisitos: ' + req_d + '\n' +
                      'Fase: ' + fase_d + '\n' + 'Cód. curso: ' + cod_curso + '\n')
        arquivo.close()
        print("Disciplina cadastrada com sucesso!")
    except IOError as error:
        print('Erro', error)

# funcao cadastro curso
def cadastro_curso():
    try:
        arquivo = open('Dados_Disc.txt', 'a')
        cod_curso = input('Código do curso: ')
        nome_c = input('Nome: ').title()
        disc_c = input('Disciplinas: ')
        cargah_c = int(input('Carga horária: '))
        fase_c = input('Fase: ')
        cod_disc = input('Código das disciplinas: ')
        arquivo.write('Código: ' + cod_curso + 'Nome: ' + nome_c + '\n' + 'Disciplinas: ' + disc_c + '\n' +
                      'Carga horaria: ' + carga_c + '\n' + 'Fases: ' + fase_c + '\n' + 'Cód. curso: ' + cod_curso + '\n')
        arquivo.close()
        print("Curso cadastrado com sucesso!")
    except IOError as error:
        print('Erro', error)

# funcao listar aluno
def listar_aluno():
    try:
        arquivo = open("Dados_Aluno.txt", "r+")
        print("Lista: \n-------")
        for linha in arquivo:
            print(linha)
            print("--------------------")
        arquivo.close()
    except IOError as error:
        print("Erro", error)

# funcao listar professor
def listar_professor():
    try:
        arquivo = open("Dados_Prof.txt", "r+")
        print("Lista: \n-------")
        for linha in arquivo:
            print(linha)
            print("--------------------")
        arquivo.close()
    except IOError as error:
        print("Erro", error)

# funcao listar disciplina
def listar_disciplina():
    try:
        arquivo = open("Dados_Disc.txt", "r+")
        print("Lista: \n-------")
        for linha in arquivo:
            print(linha)
            print("--------------------")
        arquivo.close()
    except IOError as error:
        print("Erro", error)

# funcao listar cursos
def listar_curso():
    try:
        arquivo = open("Dados_Curso.txt", "r+")
        print("Lista: \n-------")
        for linha in arquivo:
            print(linha)
            print("--------------------")
        arquivo.close()
    except IOError as error:
        print("Erro", error)

# funcoes alterar aluno
def alterar_aluno(nome_a):
    try:
        with open('Dados.txt', 'r') as arquivo:
            linhas = arquivo.readlines()
            for elemento in linhas:
                if elemento.startswith(nome_a):
                    nome_a = input('Nome completo: ').title()
                    idade_a = input('Idade: ')
                    matricula_a = input('Matrícula: ')
                    cpf_a = input('CPF: ')
                    curso_a = input('Curso matriculado: ')
                    cod_curso = input('Código do curso: ')
                    pos = linhas.index(elemento)
                    item_a = ('Nome: '+ nome_a + '\n' + 'Idade: '+ idade_a + '\n' + 'Matrícula: ' + matricula_a + '\n'+
                              'CPF: '+ cpf_a + '\n' + 'Cursando: ' + curso_a + '\n' +'Código curso: '+ cod_curso +'\n')
                    linhas.pop(pos)
                    linhas.insert(pos, item_a)
                    arquivo = open('Dados_Aluno.txt', 'w')
                    arquivo.writelines(linhas)
                    arquivo.close()
                    print("Alteração realizada com sucesso!")
    except IOError as error:
        print('Erro', error)

# funcoes alterar professor
def alterar_professor(nome_p):
    try:
        with open('Dados_Prof.txt', 'r') as arquivo:
            linhas = arquivo.readlines()
            for elemento in linhas:
                if elemento.startswith(nome_p):
                    cod_prof = input('Código do professor: ')
                    nome_p = input('Nome completo: ').title()
                    idade_p = input('Idade: ')
                    cpf_p = input('CPF: ')
                    curso_p = input('Curso matriculado: ')
                    salario_p = float(input('Salário: '))
                    cod_curso = input('Código do curso: ')
                    cod_disc = input('Código da disciplina: ')
                    item_p = ('Código: ' + cod_prof + 'Nome: ' + nome_a + '\n' + 'Idade: '+ idade_a + '\n' + 'CPF: '
                              + cpf_p +'\n' + 'Curso: '+ curso_p + '\n' + 'Salario: '+ salario_p +'\n' +'Cód. curso: '+
                              cod_curso + '\n' + 'Cód. Disciplina: ' + cod_disc + '\n')
                    pos = linhas.index(elemento)
                    linhas.pop(pos)
                    linhas.insert(pos, item_p)
                    arquivo = open('Dados_Prof.txt', 'w')
                    arquivo.writelines(linhas)
                    arquivo.close()
                    print("Alteração realizada com sucesso!")
    except IOError as error:
        print('Erro', error)
    
# funcoes alterar disciplinas
def alterar_disciplina(nome_d):
    try:
        with open('Dados_Disc.txt', 'r') as arquivo:
            linhas = arquivo.readlines()
            for elemento in linhas:
                if elemento.startswith(nome_d):
                    cod_disc = input('Código da disciplina: ')
                    nome_d = input('Nome: ').title()
                    req_d = input('Pré-requisitos: ')
                    cargah_d = int(input('Carga horária: '))
                    fase_d = input('Fase: ')
                    cod_curso = input('Código do curso: ')
                    item_d = ('Código: '+ cod_disc + 'Nome: '+ nome_d + '\n' + 'Pré-requisitos: '
                              + req_d + '\n' + 'Fase: '+ fase_d + '\n' + 'Cód. curso: '+ cod_curso + '\n')
                    pos = linhas.index(elemento)
                    linhas.pop(pos)
                    linhas.insert(pos, item_d)
                    arquivo = open('Dados_Disc.txt', 'w')
                    arquivo.writelines(linhas)
                    arquivo.close()
                    print("Alteração realizada com sucesso!")
    except IOError as error:
        print('Erro', error)


# funcoes alterar cursos
def alterar_cursos(nome_c):
    try:
        with open('Dados_Curso.txt', 'r') as arquivo:
            linhas = arquivo.readlines()
            for elemento in linhas:
                if elemento.startswith(nome_c):
                    arquivo = open('Dados_Disc.txt', 'a')
                    cod_curso = input('Código do curso: ')
                    nome_c = input('Nome: ').title()
                    disc_c = input('Disciplinas: ')
                    cargah_c = int(input('Carga horária: '))
                    fase_c = input('Fase: ')
                    cod_disc = input('Código das disciplinas: ')
                    item_c = ('Código: ' + cod_curso + 'Nome: '+ nome_c + '\n' + 'Disciplinas: ' + disc_c + '\n' +
                              'Carga horaria: '+ carga_c + '\n' + 'Fases: ' + fase_c + '\n' + 'Cód. curso: '+
                              cod_curso + '\n')
                    pos = linhas.index(elemento)
                    linhas.pop(pos)
                    linhas.insert(pos, item_c)
                    arquivo = open('Dados_Curso.txt', 'w')
                    arquivo.writelines(linhas)
                    arquivo.close()
                    print("Alteração realizada com sucesso!")
    except IOError as error:
        print('Erro', error)

# funcao excluir alunos
def excluir_aluno(nome_a):
    try:
        arquivo = open("Dados_Aluno.txt", "r")
        linhas = arquivo.readlines()
        for linha in linhas:
            if linha.startswith(nome_a):
                pos = linhas.index(linha)
                linhas.pop(pos)
                arquivo = open("Dados_Aluno.txt", "w")
                arquivo.writelines(linhas)
        arquivo.close()
        print("Aluno removido! \n")
        return 0
    except IOError as error:
        print("ERRO: ", error)

# funcao excluir professor
def excluir_professor(nome_p):
    try:
        arquivo = open("Dados_Prof.txt", "r")
        linhas = arquivo.readlines()
        for linha in linhas:
            if linha.startswith(nome_p):
                pos = linhas.index(linha)
                linhas.pop(pos)
                arquivo = open("Dados_Prof.txt", "w")
                arquivo.writelines(linhas)
        arquivo.close()
        print("Professor removido! \n")
        return 0
    except IOError as error:
        print("ERRO: ", error)

# funcao excluir disciplina
def excluir_disciplina(nome_d):
    try:
        arquivo = open("Dados_Disc.txt", "r")
        linhas = arquivo.readlines()
        for linha in linhas:
            if linha.startswith(nome_d):
                pos = linhas.index(linha)
                linhas.pop(pos)
                arquivo = open("Dados_Disc.txt", "w")
                arquivo.writelines(linhas)
        arquivo.close()
        print("Disciplina removida! \n")
        return 0
    except IOError as error:
        print("ERRO: ", error)

# funcao excluir curso
def excluir_curso(nome_c):
    try:
        arquivo = open("Dados_Curso.txt", "r")
        linhas = arquivo.readlines()
        for linha in linhas:
            if linha.startswith(nome_c):
                pos = linhas.index(linha)
                linhas.pop(pos)
                arquivo = open("Dados_Curso.txt", "w")
                arquivo.writelines(linhas)
        arquivo.close()
        print("Curso removido! \n")
        return 0
    except IOError as error:
        print("ERRO: ", error)


# funcao backup aluno
def copiar_aluno():
    try:
        arquivo1 = open("Dados_Aluno.txt", "r")
        arquivo2 = open("copia_Dados_Aluno.txt", "w")
        for texto in arquivo1:
            arquivo2.write(texto)
        arquivo1.close()
        arquivo2.close()
    except IOError as error:
        print("ERRO: ", error)

# funcao backup aluno
def copiar_professor():
    try:
        arquivo1 = open("Dados_Prof.txt", "r")
        arquivo2 = open("copia_Dados_Prof.txt", "w")
        for texto in arquivo1:
            arquivo2.write(texto)
        arquivo1.close()
        arquivo2.close()
    except IOError as error:
        print("ERRO: ", error)


# funcao backup disciplina
def copiar_disciplina():
    try:
        arquivo1 = open("Dados_Disc.txt", "r")
        arquivo2 = open("copia_Dados_Disc.txt", "w")
        for texto in arquivo1:
            arquivo2.write(texto)
        arquivo1.close()
        arquivo2.close()
    except IOError as error:
        print("ERRO: ", error)


# funcao backup curso
def copiar_curso():
    try:
        arquivo1 = open("Dados_Curso.txt", "r")
        arquivo2 = open("copia_Dados_Curso.txt", "w")
        for texto in arquivo1:
            arquivo2.write(texto)
        arquivo1.close()
        arquivo2.close()
    except IOError as error:
        print("ERRO: ", error)