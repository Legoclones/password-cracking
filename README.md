# Password Cracking Setup README
This details my password cracking setup with John the Ripper.

## Wordlists
* crackStation.txt (14.6 GB)
    * This is a list from [crackstation.net](https://crackstation.net/crackstation-wordlist-password-cracking-dictionary.htm) that contains every wordlist, dictionary, and password database leak that the creator could find, along with every word in Wikipedia from 2010 and books from Project Gutenberg. 
* dictionary.txt (392 KB)
    * This is a wordlist I've compiled that has the 52,000 most common words, animals, names, colors, elements, foods, jobs, and cities. This isn't meant to be exhaustive, but rather have words that the general public would most likely use in a password.
* dictionaryRules.txt (204 GB)
    * This wordlist is dictionary.txt, but modified according to johnrules.rul's personal rule list. 
* doubleDictionary.txt (36.5 GB)
    * This wordlist has each entry in dictionary.txt concatenated with every other entry in dictionary.txt (ie, mycat mybed myharp ...)

## How to Compile Wordlists
* Download crackStation.txt from [crackstation.net](https://crackstation.net/crackstation-wordlist-password-cracking-dictionary.htm)
    * Depending on download and file read/write speeds, this can take approximately 20 minutes
* Edit the john.conf file and insert the personal and personalShort rules found in johnrules.rul
* Using dictionary.txt, run the command `john --wordlist=dictionary.txt --rules=personal --stdout > dictionaryRules.txt` to produce dictionaryRules.txt
    * This takes around 1.5 hours
* Make an exact copy of dictionary.txt and name it dictionary2.txt
* Compile and run the doubleDictionary.cpp file to produce the doubleDictionary.txt wordlist
    * This .cpp file uses both dictionary.txt and dictionary2.txt files, so make sure they are in the same directory
    * Producing doubleDictionary.txt from the .cpp file took me approximately 4 hours

## Personalized Wordlist
The point of list of details is to find words that aren't on my wordlist, or uncommon words/phrases

First name:
Middle names:
Last names:
Nicknames: 
Street number:
Street name:
Apt #:
City:
State:
Country:
Old house street numbers:
Old house street names:
Old house apt #s:
Old house cities:
Old house states:
Old house countries:
Phone #s:
Parent/grandparent/spouse/children phone #s:
Emails:
Current/old school names:
Current/old school mascots:
Company/old company names:
Company/old company positions:
Favorite sports teams:
Favorite books:
Favorite movies:
Favorite TV show:
Favorite colors:
Favorite foods:
Others:
Hobbies:
Languages spoken:
Birthday:
Birth city:
Birth state:
Birth country:
Partner first names:
Partner middle names:
Partner last names:
Parents first names:
Parents middle names:
Parents last names:
Children first names:
Children middle names:
Children last names:
Pet names:
Other info:

## Applying Password Cracking Setup
John the Ripper can normally go through an 8 GB wordlist in a minute.

1. Use the crackStation.txt wordlist with no rules (~2 minutes)
2. Use the dictionaryRules.txt wordlist with no rules (~25 minutes)
3. Use the doubleDictionary.txt wordlist with the personal(short?) rule list (~?)
4. At this point, you can either make a personalized wordlist or incremental ASCII