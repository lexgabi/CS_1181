#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;

/*
* Lexee Gabiola
* 11/15/2022
* This function accepts a string, position, and length, and returns a subset of the string
* with a section removed.
*/
void stringPortion(string s, int p, int l) {
    cout << "Resulting string: " + s.substr(0, p) + s.substr(p + l, s.length() - 1) << endl;
}

/*
* Lexee Gabiola
* 11/15/2022
* This function returns the mean of the sum of an integer array
*/
int mean(int a[]) {
    int sum = 0;
    for (int i = 0; i < 100; ++i) {
        sum += a[i];
    }
    int mean = sum / 100;
    return mean;
}

/*
* Lexee Gabiola
* 11/15/2022
* This function accepts an integer array and returns the standard deviation.
*/
int standardDerivation(int a[]) {
    int m = mean(a);
    int sumDiff = 0;
    for (int i = 0; i < 100; ++i) {
        sumDiff += pow(a[i] - m, 2);
    }
    int stanDeriv = sqrt(sumDiff / 100);
    return stanDeriv;
}
/*
* Lexee Gabiola
* 11/15/2022
* This function accepts a target and returns how many times the target occurs in an array.
*/
int frequencyCount(int a[], int t) {
    int targetNumber = 0;
    for (int i = 0; i < 100; ++i) {
        if (a[i] == t) {
            targetNumber += 1;
        }
    }
    return targetNumber;
}

/*
* Lexee Gabiola
* 11/15/2022
* This function returns the mode of the value in an array.
*/
int modeValue(int a[],int length) {
    int mode = a[0];
    for (int i = 1; i < length; ++i) {
        if (frequencyCount(a, a[i]) > frequencyCount(a, mode)) {
            mode = a[i];
        }
        else if (frequencyCount(a, a[i]) == frequencyCount(a, mode)) {
            if (mode > a[i]) {
                mode = a[i];
            }
        }
    }
    return mode;
}

/*
* Lexee Gabiola
* 11/15/2022
* This function converts a string to an array of integers and finds the mode, returning it as
* a char.
*/
int emmaMode() {
    string emma =
        "Emma Woodhouse, handsome, clever, and rich, with a comfortable home and "
"happy disposition, seemed to unite some of the best blessings of"
"existence; and had lived nearly twenty-one years in the world with very"
"little to distress or vex her."
"She was the youngest of the two daughters of a most affectionate,"
"indulgent father; and had, in consequence of her sister’s marriage,"
"been mistress of his house from a very early period. Her mother had"
"died too long ago for her to have more than an indistinct remembrance"
"of her caresses; and her place had been supplied by an excellent woman"
"as governess, who had fallen little short of a mother in affection."
"Sixteen years had Miss Taylor been in Mr. Woodhouse’s family, less as a"
"governess than a friend, very fond of both daughters, but particularly"
"of Emma. Between _them_ it was more the intimacy of sisters. Even"
"before Miss Taylor had ceased to hold the nominal office of governess,"
"the mildness of her temper had hardly allowed her to impose any"
"restraint; and the shadow of authority being now long passed away, they"
"had been living together as friend and friend very mutually attached,"
"and Emma doing just what she liked; highly esteeming Miss Taylor’s"
"judgment, but directed chiefly by her own."
"The real evils, indeed, of Emma’s situation were the power of having"
"rather too much her own way, and a disposition to think a little too"
"well of herself; these were the disadvantages which threatened alloy to"
"her many enjoyments. The danger, however, was at present so"
"unperceived, that they did not by any means rank as misfortunes with"
"her."
"Sorrow came—a gentle sorrow—but not at all in the shape of any"
"disagreeable consciousness.—Miss Taylor married. It was Miss Taylor’s"
"loss which first brought grief. It was on the wedding-day of this"
"beloved friend that Emma first sat in mournful thought of any"
"continuance. The wedding over, and the bride-people gone, her father"
"and herself were left to dine together, with no prospect of a third to"
"cheer a long evening. Her father composed himself to sleep after"
"dinner, as usual, and she had then only to sit and think of what she"
"had lost."
"The event had every promise of happiness for her friend. Mr. Weston was"
"a man of unexceptionable character, easy fortune, suitable age, and"
"pleasant manners; and there was some satisfaction in considering with"
"what self-denying, generous friendship she had always wished and"
"promoted the match; but it was a black morning’s work for her. The want"
"of Miss Taylor would be felt every hour of every day. She recalled her"
"past kindness—the kindness, the affection of sixteen years—how she had"
"taught and how she had played with her from five years old—how she had"
"devoted all her powers to attach and amuse her in health—and how nursed"
"her through the various illnesses of childhood. A large debt of"
"gratitude was owing here; but the intercourse of the last seven years,"
"the equal footing and perfect unreserve which had soon followed"
"Isabella’s marriage, on their being left to each other, was yet a"
"dearer, tenderer recollection. She had been a friend and companion such"
"as few possessed: intelligent, well-informed, useful, gentle, knowing"
"all the ways of the family, interested in all its concerns, and"
"peculiarly interested in herself, in every pleasure, every scheme of"
"hers—one to whom she could speak every thought as it arose, and who had"
"such an affection for her as could never find fault."
"How was she to bear the change?—It was true that her friend was going"
"only half a mile from them; but Emma was aware that great must be the"
"difference between a Mrs. Weston, only half a mile from them, and a"
"Miss Taylor in the house; and with all her advantages, natural and"
"domestic, she was now in great danger of suffering from intellectual"
"solitude. She dearly loved her father, but he was no companion for her."
"He could not meet her in conversation, rational or playful."
"The evil of the actual disparity in their ages (and Mr. Woodhouse had"
"not married early) was much increased by his constitution and habits;"
"for having been a valetudinarian all his life, without activity of mind"
"or body, he was a much older man in ways than in years; and though"
"everywhere beloved for the friendliness of his heart and his amiable"
"temper, his talents could not have recommended him at any time."
"Her sister, though comparatively but little removed by matrimony, being"
"settled in London, only sixteen miles off, was much beyond her daily"
"reach; and many a long October and November evening must be struggled"
"through at Hartfield, before Christmas brought the next visit from"
"Isabella and her husband, and their little children, to fill the house, "
"and give her pleasant society again."
"Highbury, the large and populous village, almost amounting to a town,"
"to which Hartfield, in spite of its separate lawn, and shrubberies, and"
"name, did really belong, afforded her no equals. The Woodhouses were"
"first in consequence there. All looked up to them. She had many"
"acquaintance in the place, for her father was universally civil, but"
"not one among them who could be accepted in lieu of Miss Taylor for"
"even half a day. It was a melancholy change; and Emma could not but"
"sigh over it, and wish for impossible things, till her father awoke,"
"and made it necessary to be cheerful. His spirits required support. He"
"was a nervous man, easily depressed; fond of every body that he was"
"used to, and hating to part with them; hating change of every kind."
"Matrimony, as the origin of change, was always disagreeable; and he was"
"by no means yet reconciled to his own daughter’s marrying, nor could"
"ever speak of her but with compassion, though it had been entirely a"
"match of affection, when he was now obliged to part with Miss Taylor"
"too; and from his habits of gentle selfishness, and of being never able"
"to suppose that other people could feel differently from himself, he"
"was very much disposed to think Miss Taylor had done as sad a thing for"
"herself as for them, and would have been a great deal happier if she"
"had spent all the rest of her life at Hartfield. Emma smiled and"
"chatted as cheerfully as she could, to keep him from such thoughts; but"
"when tea came, it was impossible for him not to say exactly as he had"
"said at dinner,";

int emmaArray[6155];
    for (int i = 0; i < 6155; ++i) {
        emmaArray[i] = emma.at(i);
    }
    return modeValue(emmaArray, 6155);
}

/*
* Lexee Gabiola
* 11/15/2022
* This function accepts an array, and returns whether it is sorted in ascending or descending
* order, or not at all.
*/
int sortingOrder(int a[], int length) {
    int descending = 0;
    int ascending = 0;
    for (int i = 0; i < length; ++i) {
        if (a[i + 1] >= a[i] && a[i] >= a[i - 1]) {
            ascending += 1;
        }
        else if (a[i + 1 <= a[i]] && a[i] <= a[i - 1]) {
            descending += 1;
        }
    }
    if (ascending > 0 && descending == 0) { return -1;  }
    else if (descending > 0 && ascending == 0) { return 1; }
    else { return 0; }
}
/*
* Lexee Gabiola
* 11/15/2022
* This function proves the above functions work.
*/
int main()
{
    string s;
    int p, l;
    cout << "Please enter a string: ";
    cin >> s;
    cout << "Please enter a position: ";
    cin >> p;
    cout << "Please enter a length: ";
    cin >> l;
    stringPortion(s, p, l);

    srand(time(0));
    int a[100];
    cout << "Random Array: " << endl;
    for (int i = 0; i < 100; ++i) {
        a[i] = rand() % 100;
        cout << a[i] << " ";
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
    cout << endl;
    cout << "Standard Derivation: " << standardDerivation(a) << endl;
    int t = rand() % 100;
    cout << "Target: " << t << endl;
    cout << "Number of targets: " << frequencyCount(a, t) << endl;
    cout << "Mode: " << modeValue(a, 100) << endl;

    int a2[10000];
    for (int i = 0; i < 10000; ++i) {
        a2[i] = rand() % 10;
    }
    cout << "Mode for 10000 Array: " << modeValue(a2, 10000) << endl;
    cout << "Mode for 10 Paragraphs of Emma: " << char(emmaMode()) << "= blank space" << endl;
    cout << "Is the random array sorted? " << sortingOrder(a, 100);
}