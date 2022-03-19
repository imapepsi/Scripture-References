# Scripture Reference Library

This program has a collection of scripture references under some tags. 
You can search the tags and see what scriptures are listed.
You can also create a personal list by entering the book, chapter, the verses.
Once you're done you can view the list you made.

#### Possible Updates

- Create your own tags
- Add scriptures to tags
- Search for a specfic reference

## Walk Through

This the welcome message the user sees at the main menu.

```
Welcome to the Scripture Reference Library!
Options
1) Search Tags
2) Add to Personal List
3) View Personal List

Please enter an option or press (0) to quit: 
```

### Option 1 - Searching Tags

View a tag by entering the corresponding number.

```
We have a collection of scriptures under various tags.

Tag List
1) Doctrine
2) Principles
3) Applications
4) Teaching Moments
5) Parables
6) Miracles
7) Warnings
8) Hope
9) Love

Please enter the tag number you'd like to see or press (0) to return: 
```

Example Tag - Miracles

```
Please enter the tag number you'd like to see or press (0) to return: 6

Miracles
1. Matthew 9:2-8
2. Matthew 9:20-22
3. Matthew 14:15-21
4. Matthew 14:25-33
5. Mark 5:25-34
6. Luke 5:12-15
7. John 2
8. John 11
```

### Option 2 - Add to Personal List

To enter your own reference start with the name of the book (can be multiple words), next the chapter.
To enter the verses specify how many you want to input then enter the verse numbers

```
Enter Book: Luke
Enter Chapter: 1
Enter Number of Verses: 3
Please enter one verse at a time and press enter.
Enter the verse: 1
Enter the verse: 2
Enter the verse: 3
```
If you enter a 0 or negative chapter/verse the program will ask again for valid input

```
Enter Book: Mark
Enter Chapter: -2
Enter the chapter: 0
Enter the chapter: 
```
```
Enter Number of Verses: 2
Please enter one verse at a time and press enter.
Enter the verse: 1
Enter the verse: -3
Enter the verse: 0
Enter the verse:
```

### Option 3 - View Personal List

To view the list you created menu option 3.

```
1. Luke 1:1-3
2. John 1:1-2
3. Matthew 5:1
```
