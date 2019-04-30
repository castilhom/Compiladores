#include "cstdio"
#include "string"
#include "iostream"
#include "cstdlib"
#include <vector>

using namespace std;

// informa??es da tabela
struct info
{
    string lexeme;
    int value;
};

// refer?ncia ? tabela de s?mbolos
typedef vector<info> table;

// a tabela de s?mbolos
table symbols;

// verifica se a vari?vel existe na tabela
bool is_there(string lexeme)
{
    for (int i = 0; i < symbols.size(); i++)
    {
        info aux = symbols[i];
        if (aux.lexeme == lexeme)
        {
            return true;
        }
    }
    return false;
}

// insere uma nova vari?vel na tabela
int key_insertion(string lexeme)
{
    if (!is_there(lexeme))
    {
        info aux;
        aux.lexeme = lexeme;
        symbols.push_back(aux);
        return symbols.size() - 1;
    }
    else
    {
        return -1;
    }
}

// insere/altera o valor de uma vari?vel
bool value_insertion(int index, int value)
{
    if (index >= 0 && index < symbols.size())
    {
        info aux = symbols[index];
        aux.value = value;
        symbols[index] = aux;
        return true;
    }
    else
    {
        return false;
    }
}

// retorna o valor de uma vari?vel
int get_value(int index)
{
   if (index >= 0 && index < symbols.size())
    {
        info aux = symbols[index];
        return aux.value;
    }
    else
    {
        return -1;
    }
}

// retorna o valor de uma vari?vel
int get_index(string lexeme)
{
   for (int i = 0; i < symbols.size(); i++)
    {
        info aux = symbols[i];
        if (aux.lexeme == lexeme)
        {
            return i;
        }
    }
    return -1;
}
// fun??o de teste
int w()
{
    int aux;
    cout << is_there("x") << endl;
    aux = key_insertion("x");
    cout << aux << endl;
    cout << is_there("x") << endl;
    cout << value_insertion(aux, 3) << endl;
    cout << get_value(aux) << endl;
}
