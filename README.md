Todo:
- Create all the specialized wordlists
- Create details program
- Search through https://github.com/topics/wordlist
- Run `comm` with all the wordlist bases
- Add base words to dictionary (https://null-byte.wonderhowto.com/how-to/use-leaked-password-databases-create-brute-force-wordlists-0184006/)
- Is is better to do rules as a dictionary or added on to rules?
- Two dictionaries?
- Better test times
- Remove symbols and characters from all wordlists
- New rules
- Add rules set

# Password Cracking Setup README
This details my password cracking setup with John the Ripper. Based on the facts listed below, all passwords are between 6 and 10 characters and there are no symbols in these wordlists. 

## Contents
* [Wordlists](#wordlists)
    * [General Wordlists](#general-wordlists)
    * [Specialized Wordlists](#specialized-wordlists)
* [How to Use](#how-to-use)
* [Time](#time)
* [Individualized Wordlists](#individualized-wordlists)

## Wordlists
### General Wordlists
* crackStation.txt (14.6 GB)
    * This is a list from [crackstation.net](https://crackstation.net/crackstation-wordlist-password-cracking-dictionary.htm) that contains every wordlist, dictionary, and password database leak that the creator could find, along with every word in Wikipedia from 2010 and books from Project Gutenberg.
* basicDictionary.txt (??? KB)
    * I want this to be a basic dictionary with common words - used for doubleDictionary and appending to specialized wordlists
    * This is a wordlist I've compiled that has the ??,000 most common words, animals, names, colors, elements, foods, jobs, body parts, and cities. This isn't meant to be exhaustive, but rather have words that the general public would most likely use in a password. All words over a length of 10 were removed and the wordlist has no symbols or uppercase characters.
* bigDictionary.txt (??? KB)
    * This contains a larger wordlist, used for password cracking and to be used with rules
* doubleDictionary.txt (??? GB)

### Specialized Wordlists
Only passwords between 6 and 10 characters long are included. Any words or names that also appear in dictionary.txt were removed from these wordlists. All symbols and capital letters have been removed. 

* starTrek.txt (??? MB)
    * This wordlist contains 400 commonly used words, major characters, nicknames, slang, etc. as the base words.
* starWars.txt (??? MB)
    * This wordlist contains 400 major characters, creatures, alien races, worlds, objects, slang, quotes, vehicles, weapons, etc. as the base words.
* harryPotter.txt (??? MB)
    * This wordlist contains 420 major characters, spells, creatures, book titles, places, items, quidditch positions, slang, etc. as the base words.
* usaCanLocations.txt (706 MB)
    * This wordlist contains 13,000 cities, counties, provinces, and states of the United States and Canada as the base words.
* gameOfThrones.txt (??? MB)
    * This wordlist contains
* internationalLocations.txt (https://simplemaps.com/data/world-cities + countries + islands + etc.)
* doctorWho.txt
* anime.txt
    * https://github.com/ryuuganime/animanga-wordlist
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
* memes.txt
* celebrities.txt
    * https://github.com/Cheroxx/custom-wordlists
* popularplaces.txt (national parks, landmarks, amusement parks, stores, etc.)
* techTerms.txt
    * https://github.com/hypn/custom-wordlists/blob/master/dev-terms.txt
    * https://github.com/wirzka/wordlists/tree/master/dirb
    * https://github.com/wirzka/wordlists/tree/master/metaploit
    * https://github.com/kkrypt0nn/Wordlists
* Other languages
    * https://github.com/xajkep/wordlists/tree/master/dictionaries
    * https://github.com/miglen/bulgarian-wordlists
    * https://github.com/baclv/vietnamese-password-dicts
    * https://github.com/sharsi1/russkiwlst
    * https://github.com/hypn/custom-wordlists
    * https://github.com/1337z/wordlists
    * https://github.com/clem9669/wordlists
    * https://github.com/Blkzer0/Wordlists
    * https://github.com/napolux/paroleitaliane
    * https://github.com/kkrypt0nn/Wordlists
    * https://github.com/serapath/bip39wordlist
* Birth country
* Most common dog names - https://github.com/Cheroxx/custom-wordlists/blob/master/pets

## How to Use
* Make sure John the Ripper and perl are installed
* Edit the john.conf file and insert the rules found in johnrules.rul
* To produce crackStation.txt
    * Download crackStation.txt from [crackstation.net](https://crackstation.net/crackstation-wordlist-password-cracking-dictionary.htm)
    * Depending on download and file read/write speeds, this can take approximately 20 minutes
* To produce engDoubleDictionary.txt
* Other useful commands
    * `perl -lne 'length()>5 && length()<11 && print' file1.txt > file2.txt;` - this perl command removes all lines that do NOT have a length of 6-10.

## Times
**Based off of my personal computer's specs. I have an i7-10510U processor (8 processing threads, 1.80 GHz base processing speed), 12 GB of RAM, and a Solid State Drive. These times were also computed with no/few other programs running.*

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
