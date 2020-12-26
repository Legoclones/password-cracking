Todo:
- Move all current wordlists to the SSD
- Compile doubleDictionary.txt and doubleDictionaryRules.txt on the SSD - fill in sizes and compilation times below
- Test the steps to make the starTrek.txt file
- Are capitals of dictionary.txt and starTrekBase.txt making it in?
- Create all the specialized wordlists
- Go through Applying Password Cracking setup and verify all the times for password cracking
- Double check everything and commit

# Password Cracking Setup README
This details my password cracking setup with John the Ripper.

## Wordlists
### General Wordlists
* crackStation.txt (14.6 GB)
    * This is a list from [crackstation.net](https://crackstation.net/crackstation-wordlist-password-cracking-dictionary.htm) that contains every wordlist, dictionary, and password database leak that the creator could find, along with every word in Wikipedia from 2010 and books from Project Gutenberg. 
* dictionary.txt (278 KB)
    * This is a wordlist I've compiled that has the 39,000 most common words, animals, names, colors, elements, foods, jobs, body parts, and cities. This isn't meant to be exhaustive, but rather have words that the general public would most likely use in a password. All words over a length of 10 were removed and the wordlist has no symbols or uppercase characters.
* dictionaryRules.txt (?? GB)
    * This wordlist is dictionary.txt, but modified according to johnrules.rul's personalDictionary rule list. Since less than 4% of passwords normally have symbols, no symbols are included in these rules. 
* doubleDictionary.txt (?? GB)
    * This wordlist has each entry in dictionary.txt concatenated with every other entry in dictionary.txt (ie, mycat mybed myharp ...). All words over a length of 10 were removed and the wordlist has no symbols or uppercase characters.
* doubleDictionaryRules.txt (??? GB)
    * This wordlist is doubleDictionary.txt, but modified according to johnrules.rul's personalDoubleDictionary rule list.

### Personalized Wordlists
* starTrek.txt (621 MB)
    * This wordlist contains 1,100 commonly used words, major characters, nicknames, slang, etc. The personalDictionary and personalSymbols rules in johnrules.rul were also applied to this wordlist.

## How to Compile Wordlists
### General Wordlists
* Make sure John the Ripper and perl are installed
* Edit the john.conf file and insert the rules found in johnrules.rul
* Make an exact copy of dictionary.txt and name it dictionary2.txt
* To produce crackStation.txt
    * Download crackStation.txt from [crackstation.net](https://crackstation.net/crackstation-wordlist-password-cracking-dictionary.htm)
    * Depending on download and file read/write speeds, this can take approximately 20 minutes
* To produce dictionaryRules.txt
    * Using dictionary.txt, run the command `john --wordlist=dictionary.txt --rules=personalDictionary --stdout > dictionaryRules1.txt`
    * To eliminate all passwords over 10 characters, run the command `perl -lne 'length()<10 && print' dictionaryRules1.txt > dictionaryRules.txt; rm dictionaryRules1.txt` (92% of passwords are between 6-10 characters in length). This cuts down the wordlist by 13 GB.
    * This takes around 10 minutes.
* To produce doubleDictionary.txt
    * Compile and run the doubleDictionary.cpp file to produce the doubleDictionary.txt wordlist
    * This .cpp file uses both dictionary.txt and dictionary2.txt files, so make sure they are in the same directory
    * Producing doubleDictionary.txt from the .cpp file took me approximately ?? hours
* To produce doubleDictionaryRules.txt
    * Using doubleDictionary.txt, run the command `john --wordlist=doubleDictionary.txt --rules=personalDoubleDictionary --stdout > doubleDictionaryRules.txt`
    * This takes around ??

### Personalized Wordlists
* To produce starTrek.txt
    * Using starTrekBase.txt, run the commands `john --wordlist=starTrekBase.txt --rules=personalDictionary --stdout > st1`, `john --wordlist=starTrekBase.txt --rules=personalSymbols --stdout > st2`, and `cat starTrekBase.txt st1 st2 > starTrek1.txt; rm st1 st2;`
    * To eliminate duplicates, run the command `sort starTrek1.txt > st1; uniq st1 > starTrek.txt; rm st1 starTrek1.txt;`
    * This takes around 10 minutes

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

## Applying Password Cracking Setup
John the Ripper can normally go through a 10 GB wordlist in a minute.

1. Use the crackStation.txt wordlist with no rules (~1.5 minutes)
    * *Note - this should be able to capture a good chunk of the passwords*
2. Use the dictionary.txt wordlist with no rules (~1 second)
3. Use the dictionaryRules.txt wordlist with no rules (~30 seconds)
    * *Note - this wordlist contains no symbols, as over 96% of passwords normally don't have any symbols*
4. Use the doubleDictionary.txt wordlist with no rules (?? minutes)
5. Use the doubleDictionaryRules.txt wordlist with no rules (?? minutes)
    * *Note - this only uses a couple of rules, any more would take up too much storage space. Step 5 is for the remaining optional rules. This also runs doubleDictionary.txt with no rules??*
9. **Optional** - If possible, use a personalized wordlist using the format above
9. **Optional** - Use the doubleDictionary.txt wordlist with the personalShort rule lists (~?)
9. **Optional** - Use incremental ASCII


dictionary.txt with personalSymbols
doubleDictionary.txt with personalSymbols?
doubleDictionary separated by _ or .?
Specialized wordlists