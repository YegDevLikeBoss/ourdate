# What is Ourdate and how does it originated?
Ourdate is a simple library for date input, storage and manipulation. I had to develop this library for study purposes in my university in Moscow. In past it was part of my coursework, but after it's completion i've decided to make library opensourse to help other students like me.

# Ourdate features
  - Input date in various formats i.e. ( DD.MM.YYYY, DD/MM/YY and even DD/MM.YYYY if you try )
  - Automatic date validity check ( will return initialised with zeroes if you enter invalid date )
  - Calculation of weekday based on date
  - Calculation of days between dates ( You need to manualy initialise two instanses of Date get their daysFrom16K fields and substact them )
  - Increasing/Decreasing date by one or n days
  
# Ourdate limitations
Ouradate works with date values ranging from 01/01/1600 to 31/12/9999
  
# Ourdate known bugs
Though this library is almost finished, it has some bugs, that I know but doesn't have enought time to fix. Below is complete ( as I know ) list of bugs:
  - When increasing date from pre-leap year to leap year 1-st of january is initialised as 0/1/YYYY. his bug is caused by incompleteness of daysToCalc() or/and maybe daysFromCalc() functions. This leads to bug #2
  - Bug #2: When you, no matter how, reach a friday of january or february of leap year, -1 is assigned to unsigned field daysFrom16K that leads to exception and causes app to immediately crash ( even if used in GUI app )
  
# Will I ever develop Ourdate
If i'll have enought passion and time then Yes!!! So feel free to email me what do you want to see in future versions.

# Credits
Most of code is written by me, except some functions that are ported from Zheem's plain C code used for study, by Zheem himself.

PS. If Zheem reads this README. Plz tell me if you want me to leave your attribution here.

# Usage
For now, just copy Ourdate.cpp file to your project's directory and reference it from your code. This file is tested on MinGW GCC but with high probability will compile on Linux and Mac. If you use VC++ compiler chande GCC specific directives to VC++ specific ones ( just delete all #ifndef stuff and add #pragma once at the begining ).

# Documentation
Documentation is listed in Ourdate.html file ( It may be outdated, but I may update it in future ).

# License
Open LICENSE.TXT file for further information

# Для Российких студентов
Если вы гуглили что-то а-ля " День недели по дате c++ ", то вы в нужном месте. Не стесняйтесь копаться в коде, модифицировать и изменять его под ваше задание. Библиотека должна вам сильно помочь.
