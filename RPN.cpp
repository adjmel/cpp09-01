#include "RPN.hpp"

RPN::RPN()
{

}

RPN::~RPN() 
{
    
}

RPN::RPN(const RPN &obj)
{
    *this = obj;
}

RPN& RPN::operator=(const RPN &obj)
{
    (void)obj;
    return *this;
}

// Fonction pour convertir un caractère numérique en entier
int RPN::scanNum(char ch) 
{
    return ch - '0';
}

// Fonction pour vérifier si un caractère est un opérateur
bool RPN::isOperator(char ch) 
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Fonction pour effectuer une opération arithmétique sur deux nombres
int RPN::operation(int a, int b, char op) 
{
    // Tableaux contenant les opérateurs et leurs résultats respectifs
    const char operators[] = {'+', '-', '*', '/'};
    const int results[] = {b + a, b - a, b * a, b / a};

    // Parcours des opérateurs pour trouver l'opération correspondante
    for (int i = 0; i < 4; ++i) 
    {
        if (op == operators[i]) //ex : si op = +
            return results[i]; // je return b + a
    }
    return INT_MIN; // Retourne INT_MIN si l'opérateur n'est pas valide
}

// Fonction pour évaluer une expression postfixe
int RPN::postfixEval(std::string postfix)
{
    std::stack<int> stk; // Création d'une pile pour stocker les opérandes
    for (size_t i = 0; i < postfix.length(); ++i) 
    {
        if (std::isdigit(postfix[i])) //si superieur a 10 return une erreur 
        {
            // Si le caractère est un chiffre, le convertir en entier et le mettre sur la pile
            stk.push(scanNum(postfix[i]));
        }

        else if (isOperator(postfix[i])) // Si le caractère est un opérateur, effectuer l'opération correspondante
        {
            int a = stk.top(); stk.pop(); // Récupérer le deuxième opérande
            int b = stk.top(); stk.pop(); // Récupérer le premier opérande
            // donc je recupere le deuxieme element avec la fonction top, puis je le supprime (pop), pareil
            // avec le premier, ce qui me laisse la place pour les nouveaux elements de ma pile
            // que j'ai calcule et que je vais push avec push ci dessous
            stk.push(operation(a, b, postfix[i])); // Effectuer l'opération et mettre le résultat sur la pile
        }
        else if ((!std::isdigit(postfix[i]) || !isOperator(postfix[i])) && postfix[i] != ' ')
            {
                std::cout << "Error" << std::endl;
                exit(1);
            }
    }
    return stk.top(); // Retourner le résultat final
}