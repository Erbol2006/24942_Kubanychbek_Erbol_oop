#include <iostream>
#include <string> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <cctype> 
using namespace std;

int main(){
    // 1. ВВод текстов 
    string text1 =
        "Sed ut perspiciatis, unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam eaque ipsa, quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt, explicabo. Nemo enim ipsam voluptatem, quia voluptas sit, aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos, qui ratione voluptatem sequi nesciunt, neque porro quisquam est, qui dolorem ipsum, quia dolor sit, amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt, ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iurereprehenderit, qui in ea voluptate velit esse, quam nihil molestiae consequatur, vel illum, qui dolorem eum fugiat, quo voluptas nulla pariatur? At vero eos et accusamus et iusto odio dignissimos ducimus, qui blanditiis praesentium voluptatum deleniti atque corrupti, quos dolores et quas molestias excepturi sint, obcaecati cupiditate non provident, similique sunt in culpa, qui officia deserunt mollitia animi, id est laborum et dolorum fuga. Et harum quidem rerum facilis est et expedita distinctio. Nam libero tempore, cum soluta nobis est eligendi optio, cumque nihil impedit, quo minus id, quod maxime placeat, facere possimus, omnis voluptas assumenda est, omnis dolor repellendus. Temporibus autem quibusdam et aut officiis debitis aut rerum necessitatibus saepe eveniet, ut et voluptates repudiandae sint et molestiae non recusandae. Itaque earum rerum hic tenetur a sapiente delectus, ut aut reiciendis voluptatibus maiores alias consequatur aut perferendis doloribus asperiores repellat.";
    string text2 = 
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    

    //подсчет частоты каждого символа в 1 тексте 
    map<char, int>freq1;
    for (char c : text1){
        freq1[c]++;
    }

    //кол-во уникальных символов в первом тексте
    cout << "Количество уникальных символов в первом тексте: " << freq1.size() << endl;

    //найдем символы, частота которых от 40 до 90(включит.)
    set<char> charsInRange;
    for (const auto& p : freq1){
        if (p.second >= 40 && p.second <= 90){
            charsInRange.insert(p.first);
        }
    }

    cout <<"\nСимволы из первого текста с частотой от 40 до 90:\n";
    for (char c : charsInRange){
        cout << "'" << c << "'->" << freq1.at(c) << " раз(а)\n";
    }

    //подсчитаем сколько раз эти символы встречаются во втором тексте
    //используем count_if + лямбда
    int totalOccurencesInText2 =count_if(
        text2.begin(), 
        text2.end(),
        [&charsInRange](char c){
            return charsInRange.find(c) != charsInRange.end();
        }
    );

    cout << "\nОбщее кол-во вхождений этих символов во втором тексте: "
         << totalOccurencesInText2 << endl;
    
    //проверим наличие хотя бы одного такого символа при помощи find_it
    auto found = find_if(
        text2.begin(),
        text2.end(), 
        [&charsInRange](char c) {
            return charsInRange.count(c) > 0; 
        }
    );

    if (found != text2.end()) {
        cout << "\nПример найденного символа из нужного диапазона: '" << *found << "'" << endl;
    } else {
        cout << "\nНи один символ из диапазона 40–90 не найден во втором тексте." << endl;
    }

    return 0; 
}