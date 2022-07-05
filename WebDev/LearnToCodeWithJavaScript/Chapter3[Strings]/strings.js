// Literal Strings
// can use '' or ""
'String';
"I'm also a string";
''; // empty string

// standard escape values also work
'\'\\';
'\n\t\r';
// etc.

// locating value
'Hello'.charAt(1); // e, 0-indexed
'Hello'[0]; // H

// searching for values
'Hello'.indexOf('l'); // 2, looks for first appearance
'Hello'.indexOf('z'); // -1, return value for not in string

'Hello'.lastIndexOf('l'); // 3, looks for the last appearance

// conditionals
'Hello'.includes('e'); // true
'Hello'.includes('z'); // false

'Hello'.startsWith('H'); // true
'Hello'.startsWith('h'); // false

'Hello'.endsWith('O'); // false
'Hello'.endsWith('o'); // true

// attributes
'Hello'.length; // 5, length of string

// arithmetic
'Java' + 'Script'; // 'JavaScript'
'Java'.concat('Script'); // equivelant to above

// case methods
const val = 'JavaScript';
val.toLowerCase(); // 'javascript'
val.toUpperCase(); // 'JAVASCRIPT'

// trim whitespace
'    Hello    '.trim(); // 'Hello'
'    Hello    '.trimStart(); // 'Hello    '
'    Hello    '.trimEnd(); // '    Hello'

// template literals, equivalent to f-strings, allows for both '' and ""
const name = 'World!';
`Hello, ${name}!`; // use of ${} to interpolate values
`
Allow 
for 
multi-line 
strings
`;

