/*
For the input of your function, you will be given one sentence.
You have to return a corrected version,
that starts with a capital letter and ends with a period (dot).

Example:

input (string): "hey, friend"
output (string): "Hey, friend."

Updated first 'h' to 'H', added '.'.

More examples:

correctSentence("greetings, friends") == "Greetings, friends."
correctSentence("Greetings, friends") == "Greetings, friends."
correctSentence("Greetings, friends.") == "Greetings, friends."
 */

export default function correctSentence(text) {
  let correctedText;
        if(text.length == 0){
           return undefined;
        } else {
            if(text[0] >= 'a' && text[0] <= 'z'){
                correctedText = text[0].toUpperCase() + text.substring(1, text.length);
            } else {
                correctedText = text;
            }
            if(correctedText[correctedText.length - 1] != '.'){
                 correctedText += '.';
            }
            return correctedText;
        }
}
