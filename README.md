Todo:
- Create all the specialized wordlists
- Create details program

# Password Cracking Setup README
This details my password cracking setup with John the Ripper.

## Contents
* [Wordlists](#wordlists)
    * [General Wordlists](#general-wordlists)
    * [Specialized Wordlists](#specialized-wordlists)
* [Applying Password Cracking Setup](#applying-password-cracking-setup)
* [How to Compile Wordlists](#how-to-compile-wordlists)
    * [General Wordlists](#general-wordlists-1)
    * [Specialized Wordlists](#specialized-wordlists-1)
* [Individualized Wordlists](#individualized-wordlists)

## Wordlists
### General Wordlists
* crackStation.txt (14.6 GB)
    * This is a list from [crackstation.net](https://crackstation.net/crackstation-wordlist-password-cracking-dictionary.htm) that contains every wordlist, dictionary, and password database leak that the creator could find, along with every word in Wikipedia from 2010 and books from Project Gutenberg.
* fewCharacters.txt (43.6 GB)
    * This contains every possible password from 1-5 characters long, all symbols included. 
* dictionary.txt (278 KB)
    * This is a wordlist I've compiled that has the 39,000 most common words, animals, names, colors, elements, foods, jobs, body parts, and cities. This isn't meant to be exhaustive, but rather have words that the general public would most likely use in a password. All words over a length of 10 were removed and the wordlist has no symbols or uppercase characters.
* dictionaryRules.txt (9.27 GB)
    * This wordlist is dictionary.txt, but modified according to johnrules.rul's personalDictionary rule list. All passwords are between 6 and 10 characters long. Since less than 4% of passwords normally have symbols, no symbols are included in these rules. 
* doubleDictionary.txt (18.5 GB)
    * This wordlist has each entry in dictionary.txt concatenated with every other entry in dictionary.txt (ie, mycat mybed myharp ...). All passwords are between 6 and 16 characters long and the wordlist has no symbols or uppercase characters.
* doubleDictionaryRules.txt (388 GB)
    * This wordlist is doubleDictionary.txt, but modified according to johnrules.rul's personalDoubleDictionary rule list. All passwords over a length of 16 were removed.

### Specialized Wordlists
In all of these wordlists, the personalDictionary and personalSymbols rules in johnrules.rul were applied. Only passwords over 5 and under 21 characters long are included.

* starTrek.txt (??? MB)
    * This wordlist contains 1,100 commonly used words, major characters, nicknames, slang, etc.
* starWars.txt (??? MB)
    * This wordlist contains 780 major characters, creatures, alien races, worlds, objects, slang, quotes, vehicles, weapons, etc.
* harryPotter.txt (??? MB)
    * This wordlist contains 1,000 major characters, spells, creatures, book titles, places, items, quidditch positions, slang, etc.
* usLocations.txt (??? MB)
    * This wordlist contains 25,000 cities, counties, and states of the United States of America.
* canadianLocations.txt (??? MB)
    * This wordlist contains 3,000 cities and provinces of Canada.
* internationalLocations.txt (https://simplemaps.com/data/world-cities + countries + islands + etc.)
* doctorWho.txt
* anime.txt
* spanish.txt
* lds.txt
* music.txt
* vehicles.txt
* marvel.txt
* outdoors.txt
* sports.txt
* videoGames.txt
* boardGames.txt
* history.txt
* lordOfTheRings.txt
* gameOfThrones.txt
* memes.txt
* celebrities.txt
* popularplaces.txt (national parks, landmarks, etc.)
* Other languages
* Birth country

## Applying Password Cracking Setup
John the Ripper can normally go through a 10 GB wordlist in a minute*.

1. Use the crackStation.txt wordlist with no rules (~1.5 minutes)
    * *Note - this should be able to capture a good chunk of the passwords*
2. Use the dictionary.txt wordlist with no rules (~1 second)
3. Use the dictionaryRules.txt wordlist with no rules (~1 minute)
    * *Note - this wordlist contains no symbols, as over 96% of passwords normally don't have any symbols*
4. Use the doubleDictionary.txt wordlist with no rules (~2 minutes)
5. Use the fewCharacters.txt wordlist with no rules (~4 minutes)
    * *Note - this wordlist contains all possible passwords between 1-5 characters*
6. Use the doubleDictionaryRules.txt wordlist with no rules (~40 minutes)
    * *Note - this only uses a couple of rules, any more would take up too much storage space. Step 9 is for the remaining optional rules.*
7. **Optional** - If possible, use an individualized wordlist using the format above
8. **Optional** - If possible, use a specialized wordlist that matches the target
9. Other options:
    * dictionary.txt with personalSymbols rule list
    * doubleDictionary.txt with personalSymbols, personalShortOne, or personalShortTwo rule lists
    * doubleDictionary.txt with words separated by _ or .
    * Incremental ASCII starting with 6 characters

**All times are based off of my personal computer's specs. I have an i7-10510U processor (8 processing threads, 1.80 GHz base processing speed), 12 GB of RAM, and a Solid State Drive. These times were also computed with no/few other programs running.*

## How to Compile Wordlists
### General Wordlists
* Make sure John the Ripper, perl, and crunch are installed
* Edit the john.conf file and insert the rules found in johnrules.rul
* Make an exact copy of dictionary.txt and name it dictionary2.txt
* To produce crackStation.txt
    * Download crackStation.txt from [crackstation.net](https://crackstation.net/crackstation-wordlist-password-cracking-dictionary.htm)
    * Depending on download and file read/write speeds, this can take approximately 20 minutes
* To produce fewCharacters.txt
    * Using crunch from the command line, run the command `crunch 1 5 -f charset.lst all -o fewCharacters.txt`
    * This takes around 30 minutes
* To produce dictionaryRules.txt
    * Using dictionary.txt, run the command `john --wordlist=dictionary.txt --rules=personalDictionary --stdout > dictionaryRules1.txt`
    * To eliminate all passwords over 10 and under 6 characters, run the command `perl -lne 'length()<11 && length()>5 && print' dictionaryRules1.txt > dictionaryRules.txt; rm dictionaryRules1.txt` (92% of passwords are between 6-10 characters in length). This cuts down the wordlist by 9 GB.
    * This takes around 40 minutes.
* To produce doubleDictionary.txt
    * Note - This .cpp file uses both dictionary.txt and dictionary2.txt files, so make sure they are in the same directory
    * Compile and run the doubleDictionary.cpp file to produce the doubleDictionary.txt wordlist
    * To eliminate all passwords over 16 and under 6 characters, run the command `perl -lne 'length()<17 && length()>5 && print' doubleDictionary.txt > doubleDictionary2.txt; rm doubleDictionary.txt; mv doubleDictionary2.txt doubleDictionary.txt`. This cuts down the wordlist by ~1 GB.
    * This takes around 2 hours.
* To produce doubleDictionaryRules.txt
    * Using doubleDictionary.txt, run the command `john --wordlist=doubleDictionary.txt --rules=personalDoubleDictionary --stdout > doubleDictionaryRules1.txt`
    * To eliminate all passwords over 16 characters, run the command `perl -lne 'length()<17 && print' doubleDictionaryRules1.txt > doubleDictionaryRules.txt; rm doubleDictionaryRules1.txt`. This cuts down the wordlist by 29 GB.
    * This takes around 20 hours.

### Specialized Wordlists
* To produce starTrek.txt, run these commands. This takes around 5 minutes. 
    * `john --wordlist=starTrekBase.txt --rules=personalDictionary --stdout > st1; john --wordlist=starTrekBase.txt --rules=personalSymbols --stdout > st2; cat starTrekBase.txt st1 st2 > starTrek1.txt; rm st1 st2; perl -lne 'length()>5 && length()<21 && print' starTrek1.txt > starTrek2.txt; rm starTrek1.txt; sort starTrek2.txt > st1; uniq st1 > starTrek.txt; rm st1 starTrek2.txt;`
* To produce starWars.txt, run these commands. This takes around 5 minutes.
    * `john --wordlist=starWarsBase.txt --rules=personalDictionary --stdout > sw1; john --wordlist=starWarsBase.txt --rules=personalSymbols --stdout > sw2; cat starWarsBase.txt sw1 sw2 > starWars1.txt; rm sw1 sw2; perl -lne 'length()>5 && length()<21 && print' starWars1.txt > starWars2.txt; rm starWars1.txt; sort starWars2.txt > sw1; uniq sw1 > starWars.txt; rm sw1 starWars2.txt;`
* To produce harryPotter.txt, run these commands. This takes around ?? minutes.
    * `john --wordlist=harryPotterBase.txt --rules=personalDictionary --stdout > hp1; john --wordlist=harryPotterBase.txt --rules=personalSymbols --stdout > hp2; cat harryPotterBase.txt hp1 hp2 > harryPotter1.txt; rm hp1 hp2; perl -lne 'length()>5 && length()<21 && print' harryPotter1.txt > harryPotter2.txt; rm harryPotter1.txt; sort harryPotter2.txt > hp1; uniq hp1 > harryPotter.txt; rm hp1 harryPotter2.txt;`
* To produce usLocations.txt, run these commands. This takes around ?? minutes.
    * `john --wordlist=usLocationsBase.txt --rules=personalDictionary --stdout > usl1; john --wordlist=usLocationsBase.txt --rules=personalSymbols --stdout > usl2; cat usLocationsBase.txt usl1 usl2 > usLocations1.txt; rm usl1 usl2; perl -lne 'length()>5 && length()<21 && print' usLocations1.txt > usLocations2.txt; rm usLocations1.txt; sort usLocations2.txt > usl1; uniq usl1 > usLocations.txt; rm usl1 usLocations2.txt;`
* To produce canadianLocations.txt, run these commands. This takes around ?? minutes.
    * `john --wordlist=canadianLocationsBase.txt --rules=personalDictionary --stdout > cl1; john --wordlist=canadianLocationsBase.txt --rules=personalSymbols --stdout > cl2; cat canadianLocationsBase.txt cl1 cl2 > canadianLocations1.txt; rm cl1 cl2; perl -lne 'length()>5 && length()<21 && print' canadianLocations1.txt > canadianLocations2.txt; rm canadianLocations1.txt; sort canadianLocations2.txt > cl1; uniq cl1 > canadianLocations.txt; rm cl1 canadianLocations2.txt;`

## Individualized Wordlists
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
Partner birthday:
Partner nickname:
Anniversary:
Parents first names:
Parents middle names:
Parents last names:
Children first names:
Children middle names:
Children last names:
Children nicknames:
Children birthdates:
Pet names:
Other info: