// tags are optionally named structs, enums, or unions

struct s {
    // the s is the tag for this struct
};

// to declare a struct of this type need to include tag type
struct s v;
struct s *p;

enum day {sun, mon, tue, wed, thu, fri, sat};
day today; // error in C, not C++
enum day tomorrow; // ok

// C puts tags in a different namespace to other objects
enum status {ok, fail}; // enum
enum status status(void); // function

// can alias with typedef to make more compact
typedef struct s {int x;} t;
typedef struct {int x;} t;

// self referential objects require the tag name
// can define the type before the definition
typedef struct tnode tnode;
struct tnode {
    int count;
    tnode *left;
    tnode *right;
} tnode;
