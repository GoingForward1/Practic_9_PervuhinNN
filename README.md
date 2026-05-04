Первухин Никита ET-112. Занятие 9-10. Вариант 20 (структурный массив с фильмами). Все задачи выполнялись последовательно.

Занятие 9.
1. Объявление структуры Movie (+struct Data и enum genre, которые стали полями для Movie)
   <img width="1446" height="507" alt="Снимок экрана (79)" src="https://github.com/user-attachments/assets/ae28996f-f69e-4e37-93c6-3c596a5690ce" />


2. Заполнение структурного массива All_Movies 20 экземлярами (фильмами).
   <img width="1281" height="576" alt="Снимок экрана (80)" src="https://github.com/user-attachments/assets/378428f3-b333-48a9-b0c1-9b53f866cdcf" />


3. Переписать из исходного массива в другой массив, информацию о фильмах, в которых снимался Киану Ривз.
   Функция movies_by_actor принимает два Movie массива, кол-во экземпляров в них и значение поля main_actor и переписывает из одного данного массива в другой экземпляры с указанным значением поля main_actor (по актеру).
   
   Вход:
   <img width="959" height="83" alt="Снимок экрана (82)" src="https://github.com/user-attachments/assets/0c0c710d-58b9-41fe-b574-5eeea43014b5" />
   
   Выход:
   <img width="328" height="98" alt="Снимок экрана (83)" src="https://github.com/user-attachments/assets/69daccce-e20f-4ebe-aead-467f5c82fa24" />
_
_
5. Новый массив отсортировать по имени режиссера по алфавиту.
   Функция movie_sort_director принимает массив и кол-во экземпляров в нем и сортирует по значению поля director (по режисеру).
   Вход:
   <img width="971" height="101" alt="Снимок экрана (84)" src="https://github.com/user-attachments/assets/930492c5-85c1-4d58-822f-0f0ea623d408" />

   Выход:
   <img width="477" height="211" alt="Снимок экрана (85)" src="https://github.com/user-attachments/assets/6080eb8e-d867-46db-9c80-82f431f56a1b" />

6.Вывести все данные по конкретному фильму.
   Функция get_info_movie принимает индекс экземпляра из структурного массива All_Movies и выводит значения его полей (информацию о фильме).

   1) Вход:
      <img width="350" height="31" alt="Снимок экрана (94)" src="https://github.com/user-attachments/assets/01c7d7e9-c6fb-4cca-8639-18e11e028f4a" />


      Выход:
      <img width="274" height="173" alt="Снимок экрана (93)" src="https://github.com/user-attachments/assets/1d94e902-2492-4a87-9f72-6cc68460bd47" />

   2) Вход:
      <img width="358" height="31" alt="Снимок экрана (96)" src="https://github.com/user-attachments/assets/1393b37f-f185-467f-a5e5-83766f360982" />

      Выход:
      <img width="288" height="167" alt="Снимок экрана (95)" src="https://github.com/user-attachments/assets/4b62247a-cc66-4c53-b6f7-5061d26ea664" />


   3) Вход:
      <img width="352" height="33" alt="цв" src="https://github.com/user-attachments/assets/bd98648f-f8c6-4be0-b615-15992666af51" />

      Выход:
      <img width="270" height="178" alt="Снимок экрана (98)" src="https://github.com/user-attachments/assets/4a376480-930a-41d9-a36a-dc056d1f1b60" />

   4) Вход:
      <img width="351" height="31" alt="а" src="https://github.com/user-attachments/assets/f73b5726-2ac4-4ba9-a478-5293ef61d2fc" />

      Выход:
      <img width="271" height="165" alt="Снимок экрана (99)" src="https://github.com/user-attachments/assets/20c41735-1dbe-4497-95e2-dbbd7855a237" />

   5) Вход:
      <img width="427" height="37" alt="d" src="https://github.com/user-attachments/assets/57db1fdf-dc4b-43d6-8e75-9ffcb59be365" />

      Выход:
      <img width="307" height="163" alt="Снимок экрана (100)" src="https://github.com/user-attachments/assets/d6312775-8953-4c61-b0a6-716677d9b872" />

7. Вывести 3 самых бюджетных мелодрамы.
      Функция melod_spend принимает структурный массив фильмов и кол-во его экземпляров и выводит 3 структуры с значением Melodrama для поля main_genre и с наименьшим значением поля spend.
   
   Вход:
   <img width="315" height="32" alt="вв" src="https://github.com/user-attachments/assets/939cc034-99e3-4729-a41a-a424accfbd63" />

   Выход:
   <img width="343" height="83" alt="Снимок экрана (101)" src="https://github.com/user-attachments/assets/75c691e8-0c5a-4a28-879f-ce3b67c83906" />

8. Реализовать функцию изменения фильма.
   Функция replace_movie принимает структурный массив и при помощи ввода с клавиатуры изменяет поля фильмов пока не остановится цикл while. (Там есть небольшая ошибка - чтобы изменить поле name, нужно в вопросе "Что вы хотите изменить?" вводить не "name", а "имя". Я тестил работу с русским языком и забыл убрать.

   Вход:
   <img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/6a057b5c-c9d4-4213-9847-0a277bf11c34" />

   Выход:
   <img width="1853" height="470" alt="Снимок экрана (103)" src="https://github.com/user-attachments/assets/7ac4be0e-f0f4-4d34-8814-3713fe82facd" />

9-10. В отдельный массив поместить все фантастические фильмы Marvel. Реализовать вывод отфильтрованных данных в виде оберточной функции.
   Функция input_marvel_filter - оберточная функция задача который вывести результат функции marvel_filter, принимающая два массива(откуда брать фильмы и куда ложить) и кол-во экземпляров в них и заполняющая второй массив структурами с значением "Марвел" для поля director и с значением "Sci-Fi" для поля "main_genre.
   
   Вход:
   <img width="873" height="79" alt="п" src="https://github.com/user-attachments/assets/897903c7-268a-459f-a0c4-5542f38c7a3e" />

   Выход:
   <img width="262" height="86" alt="Снимок экрана (106)" src="https://github.com/user-attachments/assets/76f467ef-2a8f-490f-a789-f5ddf36b1535" />


Занятие 10.
1.




   

   











      




   




   


