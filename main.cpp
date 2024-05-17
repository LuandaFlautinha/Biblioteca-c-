#include <iostream>
#include <vector>
#include "Book.h"
#include "User.h"
#include "Loan.h"
#include "AVLTree.h"
#include <locale.h>

using namespace std;

int main() {
    AVLTree<Book> bookTree;
    AVLTree<User> userTree;
    vector<Loan> loanList;
    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Adicionar Livro" << endl;
        cout << "2. Remover Livro" << endl;
        cout << "3. Buscar Livro" << endl;
        cout << "4. Listar Livros" << endl;
        cout << "5. Adicionar Usuario" << endl;
        cout << "6. Remover Usuario" << endl;
        cout << "7. Buscar Usuario" << endl;
        cout << "8. Listar Usuarios" << endl;
        cout << "9. Registrar Emprastimo" << endl;
        cout << "10. Registrar Devolucao" << endl;
        cout << "11. Listar Emprestimos" << endl;
        cout << "0. Sair" << endl;;
        cout << "Escolha uma opcao: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Book book;
                cout << "ISBN: ";
                cin >> book.isbn;
                cout << "Titulo: ";
                cin.ignore();
                getline(cin, book.title);
                cout << "Autor: ";
                getline(cin, book.author);
                cout << "Numero de Paginas: ";
                cin >> book.pages;
                bookTree.insert(book.isbn, book);
                break;
            }
            case 2: {
                string isbn;
                cout << "ISBN do livro a ser removido: ";
                cin >> isbn;
                bookTree.remove(isbn);
                break;
            }
            case 3: {
                string isbn;
                cout << "ISBN do livro a ser buscado: ";
                cin >> isbn;
                Book* book = bookTree.search(isbn);
                if (book != nullptr) {
                    cout << "Titulo: " << book->title << ", Autor: " << book->author << ", Paginas: " << book->pages << endl;
                } else {
                    cout << "Livro nao encontrado." << endl;
                }
                break;
            }
            case 4: {
                bookTree.displayInOrder();
                break;
            }
            case 5: {
                User user;
                cout << "ID do Usuario: ";
                cin >> user.userId;
                cout << "Nome: ";
                cin.ignore();
                getline(cin, user.name);
                cout << "Dados de Contato: ";
                getline(cin, user.contactInfo);
                userTree.insert(user.userId, user);
                break;
            }
            case 6: {
                string userId;
                cout << "ID do usuario a ser removido: ";
                cin >> userId;
                userTree.remove(userId);
                break;
            }
            case 7: {
                string userId;
                cout << "ID do usuario a ser buscado: ";
                cin >> userId;
                User* user = userTree.search(userId);
                if (user != nullptr) {
                    cout << "Nome: " << user->name << ", Contato: " << user->contactInfo << endl;
                } else {
                    cout << "Usuario n�o encontrado." << endl;
                }
                break;
            }
            case 8: {
                userTree.displayInOrder();
                break;
            }
            case 9: {
                Loan loan;
                cout << "ISBN do Livro: ";
                cin >> loan.bookISBN;
                cout << "ID do Usuario: ";
                cin >> loan.userId;
                cout << "Data de Emprestimo: ";
                cin.ignore();
                getline(cin, loan.loanDate);
                cout << "Data de Devolucao Prevista: ";
                getline(cin, loan.returnDate);
                loanList.push_back(loan);
                break;
            }
            case 10: {
                string bookISBN, userId;
                cout << "ISBN do Livro: ";
                cin >> bookISBN;
                cout << "ID do Usu�rio: ";
                cin >> userId;
                auto it = remove_if(loanList.begin(), loanList.end(), [&](Loan& loan) {
                    return loan.bookISBN == bookISBN && loan.userId == userId;
                });
                if (it != loanList.end()) {
                    loanList.erase(it, loanList.end());
                    cout << "Devolucao registrada com sucesso." << endl;
                } else {
                    cout << "Emprestimo nao encontrado." << endl;
                }
                break;
            }
            case 11: {
                for (const auto& loan : loanList) {
                    cout << "Livro ISBN: " << loan.bookISBN << ", Usuario ID: " << loan.userId << ", Data de Emprestimo: " << loan.loanDate << ", Data de Devolucao: " << loan.returnDate << endl;
                }
                break;
            }
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
