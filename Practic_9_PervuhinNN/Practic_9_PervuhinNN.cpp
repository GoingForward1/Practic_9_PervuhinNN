#include <iostream>
#include <fstream>
#include <cstring>
#include <Windows.h>
using namespace std;

enum genre { Romance, Melodrama, Drama, Action, Sci_Fi, Crime, Horror, Comedy, Neowestern, Detective, Anime};
const char* genre_translate[11] = { "Романтика", "Мелодрама", "Драма", "Боевик", "Фантастика", "Криминал", "Ужасы", "Комедия", " Неовестрн", "Дедектив", "Аниме" };

struct Date {	//Дата выхода фильма
	short int day;
	short int month;
	short int year;
};

struct Movie {	//Фильм
	Date release;
	short int duration;
	unsigned int spend;	//бюджет в $
	genre main_genre;
	short int rating;	// (float)rating/10 = рейтинг фильма на кинопоиске.
	char name[48];
	char director[40];
	char main_actor[48];
	//6+2+4+4+2+48+40+48= 10+8+96+40 = 104+50=154(+2 пустых)
};


//1. Создание массива из фильмов с Киану Ривзом(и не только с ним).
static void movies_by_actor(Movie* from, int len_from, Movie* to, int& len_to, const char actor[]) {
	std::cout << "Фильмы с " << actor << " в главных ролях: \n";
	for (int i = 0; i < len_from; i++) {
		if (strcmp(from[i].main_actor, actor) == 0) {
			to[len_to] = from[i];
			std::cout << to[len_to].name << "\n";
			len_to++;
		}
	}
	std::cout << "\n";
}

//2. Новый массив отсортировать по имени режиссера по алфавиту.
static void movie_sort_director(Movie* mov /*<-Массив с фильмами*/, int count /*<-Кол-во фильмов в массиве*/) {
	int ind = count - 1;
	std::cout << "Исходный массив:\n";
	for (int i = 0; i <= ind; i++) {
		std::cout << i + 1 <<") " << mov[i].name << " от " << mov[i].director << "\n";
	}
	for (int i = 0; i <= ind; i++) {
		for (int j = ind; j >= i; j--) {
			if (strcmp(mov[j - 1].director, mov[j].director)>0) {
				Movie t = mov[j];
				mov[j] = mov[j-1];
				mov[j-1] = t;
			}
		}
	}
	std::cout << "Отсортированный массив:\n";
	for (int i = 0; i <=  ind; i++) {
		std::cout << i + 1 << ") " << mov[i].name << " от " << mov[i].director << "\n";
	}
	std::cout << "\n";

}

//3. Вывести все данные по конкретному фильму.
static void get_info_movie(Movie* mov, int ind) {
	Movie* t = &mov[ind];
	std::cout <<"Фильм: " << t->name << ";\n"
		<< "Дата выхода: ";
	printf("%02d.%02d.%4d;", t->release.day, t->release.month, t->release.year);
		std::cout << "\nБюджет: " << t->spend << "$;\n"
		<< "Жанр: " << genre_translate[t->main_genre] << ";\n"
		<< "Рейтинг на кинопоиске: " << (float)(t->rating) / 10 << ";\n"
		<< "Режисер: " << t->director << ";\n"
		<< "Главный актер: " << t->main_actor << ".\n\n";
}

//4. Вывести 3 самых бюджетных мелодрамы.
void melod_spend(Movie* mov, int count) {
	Movie mov1[21];
	int copy_ind = 0;
	for (int i = 0; i < count; i++) {
		if (mov[i].main_genre == 1) {
			mov1[copy_ind] = mov[i];
			copy_ind++;
		}
	}

	for (int i = 0; i <= copy_ind; i++) {
		for (int j = copy_ind; j > i; j--) {
			if (mov1[j].spend < mov1[j - 1].spend) {
				Movie t = mov1[j];
				mov1[j] = mov1[j - 1];
				mov1[j - 1] = t;
			}
		}
	}
	std::cout << "Самые бюджетные мелодрамы:\n1) " << mov1[0].name << " (" << mov1[0].spend << "$)\n2) " << mov1[1].name << " (" << mov1[1].spend << "$)\n3) " << mov1[2].name << " (" << mov1[2].spend << "$)\n\n";
}

//5.Реализовать функцию изменения фильма.
static void replace_movie(Movie* mov) {
	int r = 1;
	while (r != 0) {
		int ind;
		char p[25];
		std::cout << "Данные о каком фильме вы хотите изменить?(укажите индекс) ";
		std::cin >> ind;
		std::cout << "Выбран фильм " << mov[ind].name << ". Что вы хотите изменить? (name, main_genre, main_actor, director, spend, release, rating, duration) ";
		std::cin >> p;
		if (strcmp("имя", p) == 0) {
			std::cout << "Введите новое имя: ";
			std::cin >> mov[ind].name;
			std::cout << "Теперь название фильма: " << mov[ind].duration;
		}
		if (strcmp("main_genre", p) == 0) {
			int t;
			std::cout << "Текущее значение: " << mov[ind].main_genre << "(" << genre_translate[mov[ind].main_genre] << ")" << ".Введите новое значение(0 - Романтика, 1 - Мелодрама, 2 - Драма, 3 - Боевик, 4 - Фантастика, 5 - Криминал, 6 - Ужасы, 7 - Комедия, 8 - Неовестрн, 9 - Дедектив, 10 - Аниме): ";
			std::cin >> t;
			mov[ind].main_genre = (genre)t;
		}
		if (strcmp("main_actor", p) == 0) {
			std::cout << "Текущее значение: " << mov[ind].main_actor << ".\nВведите новое значение";
			std::cin >> mov[ind].main_actor;
		}
		if (strcmp("director", p) == 0) {
			std::cout << "Текущее значение: " << mov[ind].director << ".\nВведите новое значение: ";
			std::cin >> mov[ind].director;
			std::cout << "Теперь значение director: " << mov[ind].director;
		}
		if (strcmp("spend", p) == 0) {
			std::cout << "Текующее значение: " << mov[ind].spend << "($).\nВведите новое значение: ";
			std::cin >> mov[ind].spend;
			std::cout << "Теперь значение spend: " << mov[ind].spend;
		}
		if (strcmp("release", p) == 0) {
			std::cout << "Текущее значение: " << (printf("%02d.%02d.%4d;", mov[ind].release.day, mov[ind].release.month, mov[ind].release.year)) << ".\nВведите новое значение(через пробел без висячих нулей): ";
			std::cin >> mov[ind].release.day >> mov[ind].release.month >> mov[ind].release.year;
			std::cout << "Теперь значение release: " << (printf("%02d.%02d.%4d;", mov[ind].release.day, mov[ind].release.month, mov[ind].release.year));
		}
		if (strcmp("rating", p) == 0) {
			std::cout << "Текущее значение: " << mov[ind].rating << ".\nВведите новое значение: ";
			std::cin >> mov[ind].rating;
			std::cout << "Теперь значение rating: " << mov[ind].rating;
		}
		if (strcmp("duration", p) == 0) {
			std::cout << "Текущее значение: " << mov[ind].duration << ".\nВведите новое значение: ";
			std::cin >> mov[ind].duration;
			std::cout << "Теперь значение duration: " << mov[ind].duration;
		}
		
		std::cout << "\nПродолжить изменения? 1 - да, 0 - нет. ";
		std::cin >> r;
		std::cout << "\n\n";
	}
}
//6. В отдельный массив поместить все фантастические фильмы Marvel. Реализовать вывод отфильтрованных данных в виде оберточной функции.
void marvel_filter(Movie* from, int len_from, Movie* to, int& len_to) {
	for (int i = 0; i < len_from; i++) {
		if (from[i].main_genre == 4 && (strcmp(from[i].director, "Марвел") == 0)) {
			to[len_to] = from[i];
			len_to++;
		}
	}
}
static void input_marvel_filter(Movie* from, int len_from, Movie* to, int& len_to) {
	marvel_filter(from, len_from, to, len_to);
	std::cout << "Фантастические фильмы Марвел:\n";
	for (int i = 0; i < len_to; i++) {
		std::cout << to[i].name << "\n";
	}
}

//Практика 10. 1. Перезапись значение поля rating на значение из файла (одна строка это "name rating").
static void replace_rating(Movie* mov, int len, const char* file) {
	ifstream fin;
	std::string str;
	fin.open(file);
		if (fin.is_open()) {
			while (!fin.eof())
			{
				fin >> str;
				for (int i = 0; i < len; i++) 
					if (str == mov[i].name) {
						fin >> mov[i].rating;
						std::cout << "Рейтинг фильма \"" << mov[i].name<< "\" изменен на значение \"" << mov[i].rating<< "\".\n";
					}
			}
		}
	fin.close();
}

//Практика 10. 2. Нужно сделать подпрограмму чтения/записи структуры в бинарный файл.
static void io_binary(const char filename[], Movie mov[]) {
	bool act;
	fstream fin;
	int ind;
	bool p = 1;
	while (p) {
		std::cout << "Что вы хотите сделать? 0 - прочитать информацию о фильме, 1 - записать новый фильм. ";
		std::cin >> act;
		if (act == 0) {
			std::cout << "Укажите порядок фильма из файла, который хотите прочитать. ";
			std::cin >> ind;
			Movie t;
			fin.open(filename, ios::binary | ios::in);
			fin.seekg((ind - 1) * sizeof(Movie));
			fin.read((char*)&t, ind * sizeof(Movie));
			get_info_movie(&t, 0);
			fin.close();
		}
		else {
			std::cout << "Укажите индекс фильма из структуры (0-20), который хотите записать в файл. ";
			std::cin >> ind;
			fin.open(filename, ios::binary | ios::app);
			if (fin.is_open()) {
				fin.write((char*)&mov[ind], sizeof(Movie));
				fin.close();
			}
		}
		std::cout << "Продолжить работу? 0 - нет, 1 - да. ";
		std::cin >> p;
	}
}



int main() {
	setlocale(LC_ALL, "Ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Movie All_Movies[] = {
	// Дата		     длина бюджет    жанр    рейтинг имя		  режисер	   актер   
	{ {29, 4, 2002}, 121, 139000000, Sci_Fi, 78, "Человек-паук", "Марвел", "Тоби Магуайер"},
	{ {27, 8, 2020}, 91, 25000000, Comedy, 57, "Билли и Тэд cнова в деле", "Дин Паризо", "Киану Ривз"},
	{ {14, 10, 2007}, 86, 15000, Horror, 63, "Паранормальное явление", "Орен Пели", "Кэти Фезерстон" },
	{ {9, 12, 2016}, 128, 30000000, Romance, 80, "Ла-Ла Ленд", "Дэмьен Шазелл", "Райян Гослинг" },
	{ {6, 11, 2014}, 169, 165000000, Sci_Fi, 87, "Интерстеллар", "Кристофер Нолан", "Меттью Макконахи" },
	{ {27, 10, 2023}, 109, 20000000, Horror, 55, "Пять ночей с фредди", "Эмма Тамми", "Джош Хатчерсон" },
	{ {3, 10, 2019}, 122, 55000000, Drama, 84, "Джокер", "Тодд Филлипс", "Хоакин Феникс" },
	{ {16, 9, 2021}, 155, 165000000, Sci_Fi, 80, "Дюна", "Дени Вильнёв", "Тимоти Шаламе" },
	{ {16, 6, 2006}, 99, 40000000, Melodrama, 78, "Дом у озера", "Алехандро Агрести", "Киану Ривз" },
	{ {19, 12, 1997}, 194, 200000000, Melodrama, 84, "Титаник", "Джеймс Кемерон", "Леонардо Ди Каприо" },
	{ {25, 1, 2002}, 101, 118000000, Melodrama, 79, "Спеши любить", "Адам Шенкман", "Шейн Уэст" },
	{ {23, 8, 2000}, 104, 10000000, Crime, 85, "Большой куш", "Гай Ричи", "Джейсон Стэтхом" },
	{ {27, 11, 2019}, 130, 40000000, Detective, 80, "Достать ножи", "Райан Джонсон", "Дэниел Крейг" },
	{ {30, 11, 1993}, 195, 22000000, Drama, 90, "Список Шиндлера", "Стивен Спилберг", "Лиам Нисон" },
	{ {26, 8, 2016}, 106, 59000000, Anime, 84, "Твое имя", "Макото Синкай", "Рюносукэ Камики" },
	{ {16, 5, 2019}, 131, 75000000, Action, 70, "Джон Уик 3", "Чад Стахелски", "Киану Ривз" },
	{ {12, 12, 1997}, 99, 10000, Action, 83, "Брат", "Алексей Балабанов", "Сергей Бордов" },
	{ {26, 4, 2019}, 181, 356000000, Sci_Fi, 84, "Мстители: Финал", "Марвел", "Роберт Дауни младший" },
	{ {30, 4, 2008}, 126, 140000000, Sci_Fi, 79, "Железный человек", "Марвел", "Роберт Дауни младший" },
	{ {9, 11, 2007}, 122, 25000000, Neowestern, 82, "Старикам здесь не место", "Братья Коэн", "Хавьер Бардем" },
	{ {14, 1, 2011}, 108, 5000000, Melodrama, 66, "Криминальная фишка Генри", "Малькольм Венвилль", "Киану Ривз"} };
	Movie Kianu_Rivse_Movies[21];
	int count_Kianu_Rivse = 0;
	movies_by_actor(All_Movies, 21, Kianu_Rivse_Movies, count_Kianu_Rivse, "Киану Ривз");
	get_info_movie(All_Movies, 0);
	movie_sort_director(Kianu_Rivse_Movies, count_Kianu_Rivse);
	melod_spend(All_Movies, 21);
	replace_movie(All_Movies);
	Movie Marvel_Fantastic[10];
	int count_Marvel_Fantasic = 0;
	input_marvel_filter(All_Movies, 21, Marvel_Fantastic, count_Marvel_Fantasic);
	replace_rating(All_Movies, 21, "File1.txt");
	io_binary("ppp.txt", All_Movies);
}