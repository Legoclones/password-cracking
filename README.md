Todo:
- Create all the specialized wordlists
- Create details program
- Search through https://github.com/topics/wordlists and wordlist, password, and password-cracking

# Password Cracking Setup README
This details my password cracking setup with John the Ripper. Based on the facts listed below, all passwords are between 6 and 10 characters and there are no symbols in these wordlists. 

## Contents
* [Password Facts](#password-facts)
* [Wordlists](#wordlists)
    * [General Wordlists](#general-wordlists)
    * [Specialized Wordlists](#specialized-wordlists)
* [Applying Password Cracking Setup](#applying-password-cracking-setup)
* [How to Compile Wordlists](#how-to-compile-wordlists)
    * [General Wordlists](#general-wordlists-1)
    * [Specialized Wordlists](#specialized-wordlists-1)
* [Individualized Wordlists](#individualized-wordlists)

## Password Facts
* Most common length - between 6 and 10 (91%)
    * Adding 5 characters give you an extra 3-5%
* One or two character sets - 95%
* Contains a non-alphanumeric character - 2%
* Derived from a name - 14%
    * Name alone - 7.7%
    * Name + numbers - 5.9%
* Derived from a place - 8%
    * Place alone - 5.1%
    * Place + numbers - 2.7%
* Derived from a dictionary word - 25%
    * Word alone - 16%
    * Word + numbers - 8.3%
* Just numbers - 14%
    * 6 digits - 6.7%
    * 4 digits - 1.1%
    * 8 digits - 3.8%
* Derived from double words, phrases, email addresses, the keyboard, and site-related words - 7.7%
* A majority of the remaining 31% of passwords relate to pop culture
* 1-2 digits appended - 30%

This means that if I use names, places, and dictionary words alone or with numbers + 4, 6, and 8 digit passwords, I can (theoretically) crack 57.3% of all passwords in a dump. 

**Sources:**
1. https://www.troyhunt.com/brief-sony-password-analysis/ (2011)
2. https://duo.com/blog/brief-analysis-of-the-gawker-password-dump (2010)
3. https://digi.ninja/projects/pipal.php (at least after 2012)
4. https://null-byte.wonderhowto.com/how-to/use-leaked-password-databases-create-brute-force-wordlists-0184006/ (2018)

## Wordlists
### General Wordlists
* crackStation.txt (14.6 GB)
    * This is a list from [crackstation.net](https://crackstation.net/crackstation-wordlist-password-cracking-dictionary.htm) that contains every wordlist, dictionary, and password database leak that the creator could find, along with every word in Wikipedia from 2010 and books from Project Gutenberg.
* dictionary.txt (278 KB)
    * This is a wordlist I've compiled that has the 39,000 most common words, animals, names, colors, elements, foods, jobs, body parts, and cities. This isn't meant to be exhaustive, but rather have words that the general public would most likely use in a password. All words over a length of 10 were removed and the wordlist has no symbols or uppercase characters.
* dictionaryRules.txt (9.27 GB)
    * This wordlist is dictionary.txt, but modified according to johnrules.rul's personalDictionary rule list. All passwords are between 6 and 10 characters long.

### Specialized Wordlists
In all of these wordlists, the personalDictionary rules in johnrules.rul were applied. Only passwords between 6 and 10 characters long are included. Any words or names that also appear in dictionary.txt were removed from these wordlists.

* starTrek.txt (31.2 MB)
    * This wordlist contains 350 commonly used words, major characters, nicknames, slang, etc. as the base words.
* starWars.txt (36.1 MB)
    * This wordlist contains 330 major characters, creatures, alien races, worlds, objects, slang, quotes, vehicles, weapons, etc. as the base words.
* harryPotter.txt (29.8 MB)
    * This wordlist contains 370 major characters, spells, creatures, book titles, places, items, quidditch positions, slang, etc. as the base words.
* usaCanLocations.txt (706 MB)
    * This wordlist contains 13,000 cities, counties, provinces, and states of the United States and Canada as the base words.
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
* popularplaces.txt (national parks, landmarks, amusement parks, stores, etc.)
* Other languages
* Birth country

## Applying Password Cracking Setup
John the Ripper can normally go through a 10 GB wordlist in a minute* while cracking MD5 hashes.

1. Use the crackStation.txt wordlist
    * *Note - this should be able to capture a good chunk of the passwords*
2. Use the dictionary.txt wordlist
3. Use the dictionaryRules.txt wordlist
4. **Optional** - If possible, use an individualized wordlist using the format above
5. **Optional** - If possible, use a specialized wordlist that matches the target
6. Incremental ASCII

**Based off of my personal computer's specs. I have an i7-10510U processor (8 processing threads, 1.80 GHz base processing speed), 12 GB of RAM, and a Solid State Drive. These times were also computed with no/few other programs running.*

## How to Compile Wordlists
* Make sure John the Ripper and perl are installed
* Edit the john.conf file and insert the rules found in johnrules.rul

### General Wordlists
* To produce crackStation.txt
    * Download crackStation.txt from [crackstation.net](https://crackstation.net/crackstation-wordlist-password-cracking-dictionary.htm)
    * Depending on download and file read/write speeds, this can take approximately 20 minutes
* To produce dictionaryRules.txt
    * Using dictionary.txt, run the command `john --wordlist=dictionary.txt --rules=personalDictionary --stdout > dictionaryRules1.txt`
    * To eliminate all passwords over 10 and under 6 characters, run the command `perl -lne 'length()<11 && length()>5 && print' dictionaryRules1.txt > dictionaryRules.txt; rm dictionaryRules1.txt`. This cuts down the wordlist by 9 GB.
    * This takes around 40 minutes.

### Specialized Wordlists
* To produce starTrek.txt, run these commands. This should take only a few seconds.
    * `john --wordlist=wordlistBases/starTrekBase.txt --rules=personalDictionary --stdout > starTrek1.txt; perl -lne 'length()>5 && length()<11 && print' starTrek1.txt > starTrek2.txt; sort starTrek2.txt > st1; uniq st1 > starTrek.txt; rm st1 starTrek1.txt starTrek2.txt;`
* To produce starWars.txt, run these commands. This should take only a few seconds.
    * `john --wordlist=wordlistBases/starWarsBase.txt --rules=personalDictionary --stdout > starWars1.txt; perl -lne 'length()>5 && length()<11 && print' starWars1.txt > starWars2.txt; sort starWars2.txt > sw1; uniq sw1 > starWars.txt; rm sw1 starWars1.txt starWars2.txt;`
* To produce harryPotter.txt, run these commands. This should take only a few seconds.
    * `john --wordlist=wordlistBases/harryPotterBase.txt --rules=personalDictionary --stdout > harryPotter1.txt; perl -lne 'length()>5 && length()<11 && print' harryPotter1.txt > harryPotter2.txt; sort harryPotter2.txt > hp1; uniq hp1 > harryPotter.txt; rm hp1 harryPotter1.txt harryPotter2.txt;`
* To produce usaCanLocations.txt, run these commands. This should take only a few minutes.
    * `john --wordlist=wordlistBases/usaCanLocationsBase.txt --rules=personalDictionary --stdout > usaCanLocations1.txt; perl -lne 'length()>5 && length()<11 && print' usaCanLocations1.txt > usaCanLocations2.txt; sort usaCanLocations2.txt > uc1; uniq uc1 > usaCanLocations.txt; rm uc1 usaCanLocations1.txt usaCanLocations2.txt;`

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
Old/current usernames:
Other info: