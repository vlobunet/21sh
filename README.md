# 21sh

задача написать шелл в котором реализовано:

Mandatory part
--------------
    редактирование командной строки
    перемещение курсора влево и вправо на символ или на слово
    перемещение курсора в начало или в конец строки
    навигация по истории
    Копирование и вставка всей или только части строки
    Выполнение всех бинарников а так же команд:
                      echo, env, setenv, unsetenv, cd, exit
    Работа с конструкциями конвеера, перенаправлений ввода/вывода
    Работа с quote и heredoc
    Обработка сигналов
  
Bonus part
-----------
    Выделение текста:
          по символьно, по слову, до конца или начала строки
    удаление:
          строки после курсора
          удаление всей строки
          удаление выделенного фрагмента
    Вырезание выделенного текста
    Разумное автодополнение:
          терминал см знает когда нужно подставить название директории
          а когда название программы
    Перемещение курсора в команде из нескольких строк разной длинны
    Работа с конструкцией когда параметры указаны после цели перенаправления
        вводв/вывода
    Конструкции комманд с операторами && и ||
    конструкции типа: 
```                          ls -l `command1` `command2` ... ```

Порядок
----------
<li>        1. принять отредактированную строку строку из клавиатуры
<li> 2. разбить строку на токены (по символьная проверка)
<li> 3. определить типы токенов и проверить валидность последовательности
<li> 4. определить приоритеты токенов и создать дерево
<li> 5. рекурсивно из самого дочернего елемента выполнить все задачи.
<li> 6. вывести результат
<li> 7. запросить ввод следующей команды
    
## Key

**Line editing** 

KEY|ACT/FUNC(en)|Функции(ru)
-:|:--|:--
<kbd>up</kbd><br><kbd>down</kbd><br><kbd>right</kbd><br><kbd>left</kbd><br>|Up one line/story up.<br>Down one line / story down.<br>Right to one character.<br>Left to one character.<br>|Вверх на 1 строку/История вверх<br>Вниз на одну строку/История вниз<br>Вправо на 1 символ<br>Влево на один символ<br>
<kbd>alt</kbd>+<kbd>right</kbd><br><kbd>alt</kbd>+<kbd>left</kbd><br>|Right to one word.<br>Left to one word.<br>|Вправо на одно слово<br>Влево на одно слово<br>
<kbd>home</kbd><br><kbd>end</kbd><br>|at the beginning of the line.<br>at the end of the line.<br>|В начало строки<br>В конец строки<br>
<kbd>backspace</kbd><br><kbd>del</kbd><br><kbd>esc</kbd><br>|removes a character or selected part of a string.<br>delete all characters after the cursor<br>Clear line / exit<br>|Удалить символ или выделенную строку<br>Удалить все символы после курсора<br>Очистить строку / выход<br>
<kbd>tab</kbd><br>|autocomplate.<br>|Автодополнение<br>
<kbd>alt</kbd>+<kbd>v</kbd><br>|Paste<br>|Вставить из буфера<br>

**Selection**

KEY|ACT/FUNC(en)|Функции(ru)
-:|:--|:--
<kbd>alt</kbd>+<kbd>shift</kbd>+<kbd>right</kbd><br><kbd>alt</kbd>+<kbd>shift</kbd>+<kbd>left</kbd>|select/deselect a word<br>right or left<br>|Выделить/снять выделение слова<br>справа или слева<br>
<kbd>shift</kbd>+<kbd>right</kbd><br><kbd>shift</kbd>+<kbd>left</kbd>|select/deselect left<br>or right symbol.<br>|Выделить/снять выделение символа справа<br>Выделить/снять выделение символа слева<br>
<kbd>shift</kbd>+<kbd>home</kbd><br><kbd>shift</kbd>+<kbd>end</kbd><br><kbd>alt</kbd>+<kbd>a</kbd>|select/deselect to beginning of line<br>select/deselect to the end of the line.<br>select an entire row.<br>|Выделить до начала <br>Выделить до конца<br>Выделить всю строку<br>
<kbd>alt</kbd>+<kbd>x</kbd><br><kbd>alt</kbd>+<kbd>c</kbd><br>|cut the selection.<br>copy the selection.<br>|Вырезать в буфер<br>Копировать в буфер<br>

**Builtins**

COMMAND|DESCRIPTIONS(en)|Описание(ru)
-:|:--|:--
`env`<br>|Print environment<br>|Отображает переменные терминала<br>
`setenv`<br>|Set environment.<br>|Настраивает переменные терминала<br>
`unsetenv`<br>|Delete environment.<br>|Удаляет переменные терминала<br>
`clear`<br>|Clear the terminal screen.<br>|Чистит экран<br>
`cd`<br>|Switch between directories.<br>|Переход между директориями<br>
`echo`<br>|Write arguments to the standard output.<br>|Отобржение на стандартный вивод<br>
`exit`<br>|Exit 21sh.<br>|Выход из терминала<br>
`help`<br>|Display help file.<br>|Помощь<br>
`man`<br>|Manual<br>|Описание к командам<br>

Автор: [Владимир Лобунец](https://profile.intra.42.fr/users/vlobunet)
