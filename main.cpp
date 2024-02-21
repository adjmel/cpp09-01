#include "RPN.hpp"

int parsing_rpn(std::string postfixExpression)
{
    // parsing si nombre superieur a 10
   // Variable pour stocker chaque nombre extrait de l'expression postfixe
    std::string currentNumber = "";

    for (size_t i = 0; i < postfixExpression.length(); ++i) 
{
    // Vérifier si le caractère est un espace ou un opérateur
    if (postfixExpression[i] == ' ') 
    {
        // Si nous avons un nombre dans currentNumber, le convertir en entier et vérifier s'il est supérieur ou égal à 10
        if (!currentNumber.empty()) 
        {
            int num = std::atoi(currentNumber.c_str()); // Convertir la chaîne de caractères en entier
            if (num >= 10 || num < 0)
            {
                std::cout << "Error: " << num << " this number is not between 0 and 9." << std::endl;
                return 1;
            }

            // Vérifier la présence de plusieurs signes consécutifs
            for (size_t j = 1; j < currentNumber.length(); ++j)
            {
                if ((currentNumber[j] == '+' || currentNumber[j] == '-' || currentNumber[j] == '*' || currentNumber[j] == '/') &&
                    (currentNumber[j - 1] == '+' || currentNumber[j - 1] == '-' || currentNumber[j - 1] == '*' || currentNumber[j - 1] == '/'))
                {
                    std::cout << "Error: there are several signs in a row" << std::endl;
                    return 1;
                }
            }

            // Réinitialiser currentNumber pour le prochain nombre
            currentNumber = "";
        }
    } 
    else 
    {
        // Concaténer le caractère au nombre actuel
        currentNumber += postfixExpression[i];
    }
}

// Vérifier le dernier nombre s'il y en a un
    if (!currentNumber.empty()) 
    {
        int num = std::atoi(currentNumber.c_str()); // Convertir la chaîne de caractères en entier
        if (num >= 10 || num < 0) 
        {
            std::cout << "Error: " << num << " this number is not between 0 and 9." << std::endl;
            return 1;
        } 

        for (size_t j = 1; j < currentNumber.length(); ++j)
            {
                if ((currentNumber[j] == '+' || currentNumber[j] == '-' || currentNumber[j] == '*' || currentNumber[j] == '/') &&
                    (currentNumber[j - 1] == '+' || currentNumber[j - 1] == '-' || currentNumber[j - 1] == '*' || currentNumber[j - 1] == '/'))
                {
                    std::cout << "Error: there are several signs in a row" << std::endl;
                    return 1;
                }
            }
    }
    return 0;
}

int main(int argc, char **argv) 
{
     // Récupérer l'expression postfixe à partir des arguments de la ligne de commande
    std::string postfixExpression = argv[1];

    // Vérifier que l'expression postfixe est fournie en argument
    if (argc < 2 || postfixExpression.compare("") == 0) 
    {
        std::cout << "Usage: " << argv[0] << " <postfix_expression>" << std::endl;
        return 1; // Retourner 1 pour indiquer une erreur
    }

    if (parsing_rpn(postfixExpression) == 1)
        return 1;

    // Afficher le résultat de l'évaluation de l'expression postfixe
    std::cout << RPN::postfixEval(postfixExpression) << std::endl;

    // Retourner 0 pour indiquer une exécution réussie
    return 0;
}