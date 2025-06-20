## Описание

Консольная утилита, которая обрабатывает аргументы командной строки и выполняет следующие действия:
- Выводит список пользователей и их домашних директорий.
- Выводит список запущенных процессов.
- Поддерживает логирование вывода в файл.
- Поддерживает перенаправление ошибок в файл.
- Выводит справку по использованию.

---
## Функциональность

Утилита поддерживает следующие аргументы командной строки:

| Аргумент          | Описание                                                                 |
|-------------------|-------------------------------------------------------------------------|
| `-u`, `--users`   | Выводит список пользователей и их домашних директорий.                  |
| `-p`, `--processes`| Выводит список запущенных процессов.                                   |
| `-l PATH`, `--log PATH` | Перенаправляет вывод в файл по указанному пути `PATH`.              |
| `-e PATH`, `--errors PATH` | Перенаправляет ошибки в файл по указанному пути `PATH`.          |
| `-h`, `--help`    | Выводит справку по использованию утилиты.                              |

---
