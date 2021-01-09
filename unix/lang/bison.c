/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */


/*

    YABASIC ---  a simple Basic Interpreter
    written by Marc Ihm 1995-2021
    more info at www.yabasic.de

    BISON part
     
    This file is part of yabasic and may be copied under the terms of
    MIT License which can be found in the file LICENSE.

*/


#ifndef YABASIC_INCLUDED
#include "yabasic.h"     /* definitions of yabasic */
#endif

#ifdef WINDOWS
#include <malloc.h>
#else
#ifdef HAVE_MALLOC_H
#include <malloc.h>
#else
#include <stdlib.h>
#endif
#endif

#if HAVE_ALLOCA_H
#ifndef WINDOWS
#include <alloca.h>
#endif
#endif

void __yy_bcopy(char *,char *,int); /* prototype missing */

int tileol; /* true, read should go to eon of line */
int function_type=ftNONE; /* contains function type while parsing function */
char *current_function=NULL; /* name of currently parsed function */
int exported=FALSE; /* true, if function is exported */
int yylex(void);
extern struct library *current_library; /* defined in main.c: name of currently parsed library */
extern int yylineno; /* defined in flex */
int missing_endif=0;
int missing_endif_line=0;
int missing_endsub=0;
int missing_endsub_line=0;
int missing_next=0;
int missing_next_line=0;
int missing_wend=0;
int missing_wend_line=0;
int missing_until=0;
int missing_until_line=0;
int missing_loop=0;
int missing_loop_line=0;
int loop_nesting=0;
int switch_nesting=0;

void report_if_missing(char *text,int eof) {
  if (missing_loop || missing_endif || missing_next || missing_until || missing_wend) {
    if (eof) {
       error_without_position(sERROR,text);
    } else {
       error(sERROR,text);
    }
    collect_missing_clauses(string,-1);
    if (string[0]) {
      error_without_position(sERROR,string);
    }
  }
}

void report_conflicting_close(char *text,int missing) {
  error(sERROR,text);
  collect_missing_clauses(string,missing);
  error(sERROR,string);
}

void collect_missing_clauses(char *string, char exclude) {
  char buff[INBUFFLEN];
  
  string[0]='\0';
  if (missing_endif && exclude!='e') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"if-statement starting at line %d has seen no 'endif' yet",missing_endif_line);
    strcat(string, buff);
  }

  if (missing_next && exclude!='n') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"for-loop starting at line %d has seen no 'next' yet",missing_next_line);
    strcat(string, buff);
  }

  if (missing_wend && exclude!='w') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"while-loop starting at line %d has seen no 'wend' yet",missing_wend_line);
    strcat(string, buff);
  }

  if (missing_until && exclude!='u') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"repeat-loop starting at line %d has seen no 'until' yet",missing_until_line);
    strcat(string, buff);
  }
  
  if (missing_loop && exclude!='l') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"do-loop starting at line %d has seen no 'loop' yet",missing_loop_line);
    strcat(string, buff);
  }
}



# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "bison.h".  */
#ifndef YY_YY_BISON_H_INCLUDED
# define YY_YY_BISON_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tFNUM = 258,
    tSYMBOL = 259,
    tSTRSYM = 260,
    tDOCU = 261,
    tDIGITS = 262,
    tHEXDIGITS = 263,
    tBINDIGITS = 264,
    tSTRING = 265,
    tFOR = 266,
    tTO = 267,
    tSTEP = 268,
    tNEXT = 269,
    tWHILE = 270,
    tWEND = 271,
    tREPEAT = 272,
    tUNTIL = 273,
    tIMPORT = 274,
    tGOTO = 275,
    tGOSUB = 276,
    tLABEL = 277,
    tON = 278,
    tSUB = 279,
    tENDSUB = 280,
    tLOCAL = 281,
    tSTATIC = 282,
    tEXPORT = 283,
    tERROR = 284,
    tEXECUTE = 285,
    tEXECUTE2 = 286,
    tCOMPILE = 287,
    tRUNTIME_CREATED_SUB = 288,
    tINTERRUPT = 289,
    tBREAK = 290,
    tCONTINUE = 291,
    tSWITCH = 292,
    tSEND = 293,
    tCASE = 294,
    tDEFAULT = 295,
    tLOOP = 296,
    tDO = 297,
    tSEP = 298,
    tEOPROG = 299,
    tIF = 300,
    tTHEN = 301,
    tELSE = 302,
    tELSIF = 303,
    tENDIF = 304,
    tIMPLICITENDIF = 305,
    tUSING = 306,
    tPRINT = 307,
    tINPUT = 308,
    tRETURN = 309,
    tDIM = 310,
    tEND = 311,
    tEXIT = 312,
    tAT = 313,
    tSCREEN = 314,
    tREVERSE = 315,
    tCOLOUR = 316,
    tBACKCOLOUR = 317,
    tAND = 318,
    tOR = 319,
    tNOT = 320,
    tBITNOT = 321,
    tEOR = 322,
    tSHL = 323,
    tSHR = 324,
    tNEQ = 325,
    tLEQ = 326,
    tGEQ = 327,
    tLTN = 328,
    tGTN = 329,
    tEQU = 330,
    tPOW = 331,
    tREAD = 332,
    tDATA = 333,
    tRESTORE = 334,
    tOPEN = 335,
    tCLOSE = 336,
    tSEEK = 337,
    tTELL = 338,
    tAS = 339,
    tREADING = 340,
    tWRITING = 341,
    tORIGIN = 342,
    tWINDOW = 343,
    tDOT = 344,
    tLINE = 345,
    tCIRCLE = 346,
    tTRIANGLE = 347,
    tTEXT = 348,
    tCLEAR = 349,
    tFILL = 350,
    tPRINTER = 351,
    tWAIT = 352,
    tBELL = 353,
    tLET = 354,
    tARDIM = 355,
    tARSIZE = 356,
    tBIND = 357,
    tRECT = 358,
    tGETBIT = 359,
    tPUTBIT = 360,
    tGETCHAR = 361,
    tPUTCHAR = 362,
    tNEW = 363,
    tCURVE = 364,
    tSIN = 365,
    tASIN = 366,
    tCOS = 367,
    tACOS = 368,
    tTAN = 369,
    tATAN = 370,
    tEXP = 371,
    tLOG = 372,
    tSQRT = 373,
    tSQR = 374,
    tMYEOF = 375,
    tABS = 376,
    tSIG = 377,
    tINT = 378,
    tCEIL = 379,
    tFLOOR = 380,
    tFRAC = 381,
    tROUND = 382,
    tMOD = 383,
    tRAN = 384,
    tVAL = 385,
    tLEFT = 386,
    tRIGHT = 387,
    tMID = 388,
    tLEN = 389,
    tMIN = 390,
    tMAX = 391,
    tSTR = 392,
    tINKEY = 393,
    tCHR = 394,
    tASC = 395,
    tHEX = 396,
    tDEC = 397,
    tBIN = 398,
    tUPPER = 399,
    tLOWER = 400,
    tMOUSEX = 401,
    tMOUSEY = 402,
    tMOUSEB = 403,
    tMOUSEMOD = 404,
    tTRIM = 405,
    tLTRIM = 406,
    tRTRIM = 407,
    tINSTR = 408,
    tRINSTR = 409,
    tCHOMP = 410,
    tSYSTEM = 411,
    tSYSTEM2 = 412,
    tPEEK = 413,
    tPEEK2 = 414,
    tPOKE = 415,
    tFRNFN_CALL = 416,
    tFRNFN_CALL2 = 417,
    tFRNFN_SIZE = 418,
    tFRNBF_ALLOC = 419,
    tFRNBF_FREE = 420,
    tFRNBF_SIZE = 421,
    tFRNBF_DUMP = 422,
    tFRNBF_SET = 423,
    tFRNBF_GET = 424,
    tFRNBF_GET2 = 425,
    tFRNBF_GET_BUFFER = 426,
    tFRNBF_SET_BUFFER = 427,
    tDATE = 428,
    tTIME = 429,
    tTOKEN = 430,
    tTOKENALT = 431,
    tSPLIT = 432,
    tSPLITALT = 433,
    tGLOB = 434,
    tSTART_PROGRAM = 435,
    tSTART_EXPRESSION = 436,
    tSTART_STRING_EXPRESSION = 437,
    tSTART_ASSIGNMENT = 438,
    tSTART_FUNCTION_DEFINITION = 439,
    tEVAL = 440,
    tEVAL2 = 441,
    UMINUS = 442
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{


  double fnum;          /* double number */
  int inum;             /* integer number */
  int token;            /* token of command */
  int sep;              /* number of newlines */
  char *string;         /* quoted string */
  char *symbol;         /* general symbol */
  char *digits;         /* string of digits */
  char *docu;		/* embedded documentation */


};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_BISON_H_INCLUDED  */

/* Copy the second part of user declarations.  */


/* Unqualified %code blocks.  */


void
yyerror(char *message) {
  error(sERROR,message);
}

void
lyyerror(int severity, char *message) {
  error(severity,message);
}



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  193
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6305

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  197
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  111
/* YYNRULES -- Number of rules.  */
#define YYNRULES  476
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1133

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   442

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   196,     2,     2,     2,     2,
     194,   195,   189,   188,   193,   187,     2,   190,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   192,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   191
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   190,   190,   191,   192,   193,   194,   197,   200,   201,
     201,   205,   206,   207,   208,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   226,   227,   227,   228,   229,   230,   231,   232,   233,
     234,   234,   236,   236,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   249,   250,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   267,   268,
     269,   270,   271,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   322,   323,
     324,   325,   326,   330,   331,   332,   333,   334,   335,   338,
     339,   342,   343,   344,   345,   346,   349,   350,   353,   354,
     357,   358,   359,   360,   361,   362,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   407,   408,   411,   411,
     412,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   445,   448,   451,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   527,   528,   529,   532,
     533,   534,   535,   538,   539,   542,   543,   544,   545,   548,
     551,   554,   554,   557,   558,   559,   562,   563,   566,   567,
     570,   566,   575,   576,   579,   580,   583,   584,   585,   586,
     589,   590,   593,   594,   595,   596,   599,   600,   603,   604,
     605,   606,   609,   610,   611,   614,   615,   616,   617,   620,
     621,   626,   641,   620,   646,   647,   648,   649,   650,   651,
     654,   655,   658,   659,   664,   664,   668,   669,   672,   673,
     677,   679,   678,   683,   684,   684,   688,   688,   694,   695,
     696,   697,   698,   699,   703,   704,   703,   710,   711,   715,
     715,   720,   721,   722,   723,   724,   725,   728,   729,   729,
     731,   728,   735,   736,   737,   738,   739,   740,   743,   743,
     748,   749,   752,   753,   756,   758,   760,   757,   764,   765,
     768,   769,   769,   772,   773,   775,   776,   780,   781,   784,
     785,   787,   788,   792,   793,   794,   795,   798,   799,   800,
     801,   802,   805,   806,   807,   810,   810,   811,   811,   812,
     812,   813,   813,   814,   814,   817,   818,   821,   822,   823,
     824,   825,   826,   827,   828,   829,   830,   831,   832,   833,
     834,   837,   838,   840,   841,   844,   845
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tFNUM", "tSYMBOL", "tSTRSYM", "tDOCU",
  "tDIGITS", "tHEXDIGITS", "tBINDIGITS", "tSTRING", "tFOR", "tTO", "tSTEP",
  "tNEXT", "tWHILE", "tWEND", "tREPEAT", "tUNTIL", "tIMPORT", "tGOTO",
  "tGOSUB", "tLABEL", "tON", "tSUB", "tENDSUB", "tLOCAL", "tSTATIC",
  "tEXPORT", "tERROR", "tEXECUTE", "tEXECUTE2", "tCOMPILE",
  "tRUNTIME_CREATED_SUB", "tINTERRUPT", "tBREAK", "tCONTINUE", "tSWITCH",
  "tSEND", "tCASE", "tDEFAULT", "tLOOP", "tDO", "tSEP", "tEOPROG", "tIF",
  "tTHEN", "tELSE", "tELSIF", "tENDIF", "tIMPLICITENDIF", "tUSING",
  "tPRINT", "tINPUT", "tRETURN", "tDIM", "tEND", "tEXIT", "tAT", "tSCREEN",
  "tREVERSE", "tCOLOUR", "tBACKCOLOUR", "tAND", "tOR", "tNOT", "tBITNOT",
  "tEOR", "tSHL", "tSHR", "tNEQ", "tLEQ", "tGEQ", "tLTN", "tGTN", "tEQU",
  "tPOW", "tREAD", "tDATA", "tRESTORE", "tOPEN", "tCLOSE", "tSEEK",
  "tTELL", "tAS", "tREADING", "tWRITING", "tORIGIN", "tWINDOW", "tDOT",
  "tLINE", "tCIRCLE", "tTRIANGLE", "tTEXT", "tCLEAR", "tFILL", "tPRINTER",
  "tWAIT", "tBELL", "tLET", "tARDIM", "tARSIZE", "tBIND", "tRECT",
  "tGETBIT", "tPUTBIT", "tGETCHAR", "tPUTCHAR", "tNEW", "tCURVE", "tSIN",
  "tASIN", "tCOS", "tACOS", "tTAN", "tATAN", "tEXP", "tLOG", "tSQRT",
  "tSQR", "tMYEOF", "tABS", "tSIG", "tINT", "tCEIL", "tFLOOR", "tFRAC",
  "tROUND", "tMOD", "tRAN", "tVAL", "tLEFT", "tRIGHT", "tMID", "tLEN",
  "tMIN", "tMAX", "tSTR", "tINKEY", "tCHR", "tASC", "tHEX", "tDEC", "tBIN",
  "tUPPER", "tLOWER", "tMOUSEX", "tMOUSEY", "tMOUSEB", "tMOUSEMOD",
  "tTRIM", "tLTRIM", "tRTRIM", "tINSTR", "tRINSTR", "tCHOMP", "tSYSTEM",
  "tSYSTEM2", "tPEEK", "tPEEK2", "tPOKE", "tFRNFN_CALL", "tFRNFN_CALL2",
  "tFRNFN_SIZE", "tFRNBF_ALLOC", "tFRNBF_FREE", "tFRNBF_SIZE",
  "tFRNBF_DUMP", "tFRNBF_SET", "tFRNBF_GET", "tFRNBF_GET2",
  "tFRNBF_GET_BUFFER", "tFRNBF_SET_BUFFER", "tDATE", "tTIME", "tTOKEN",
  "tTOKENALT", "tSPLIT", "tSPLITALT", "tGLOB", "tSTART_PROGRAM",
  "tSTART_EXPRESSION", "tSTART_STRING_EXPRESSION", "tSTART_ASSIGNMENT",
  "tSTART_FUNCTION_DEFINITION", "tEVAL", "tEVAL2", "'-'", "'+'", "'*'",
  "'/'", "UMINUS", "';'", "','", "'('", "')'", "'#'", "$accept",
  "program_or_expression", "program", "statement_list", "$@1",
  "assignment", "statement", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7",
  "clear_fill_clause", "string_assignment", "to", "open_clause",
  "seek_clause", "string_scalar_or_array", "string_expression",
  "string_function", "number_assignment", "expression", "$@8", "$@9",
  "arrayref", "string_arrayref", "coordinates", "function", "const",
  "number", "symbol_or_lineno", "dimlist", "function_or_array",
  "stringfunction_or_array", "call_list", "$@10", "calls", "call_item",
  "function_definition", "$@11", "$@12", "$@13", "endsub", "function_name",
  "export", "local_list", "local_item", "static_list", "static_item",
  "paramlist", "paramitem", "for_loop", "$@14", "$@15", "$@16", "$@17",
  "next", "step_part", "next_symbol", "switch_number_or_string", "$@18",
  "sep_list", "number_or_string", "case_list", "$@19", "default", "$@20",
  "do_loop", "$@21", "loop", "while_loop", "$@22", "$@23", "wend",
  "repeat_loop", "$@24", "until", "if_clause", "$@25", "$@26", "$@27",
  "$@28", "endif", "short_if", "$@29", "end_of_if", "else_part",
  "elsif_part", "$@30", "$@31", "maybe_then", "inputlist", "$@32", "input",
  "readlist", "readitem", "datalist", "printlist", "using", "inputbody",
  "$@33", "$@34", "$@35", "$@36", "$@37", "prompt", "printintro",
  "hashed_number", "goto_list", "gosub_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,    45,    43,    42,
      47,   442,    59,    44,    40,    41,    35
};
# endif

#define YYPACT_NINF -821

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-821)))

#define YYTABLE_NINF -398

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     613,  4003,  3479,  2606,    21,    62,    39,   -38,   -37,  -821,
    -821,  -821,  -821,  -821,    41,    41,    41,  3103,  -821,  -821,
    -821,  2606,  -821,  -821,  2606,    79,    84,  -821,  -821,  -821,
    3479,   -31,  -821,  3479,    18,  -821,  3479,  3479,  3479,    76,
      43,    41,  1754,  1186,  2142,    52,  3479,  2915,  3479,   377,
      10,  3479,  -821,    63,  2606,  2606,  2606,   -53,   -32,    -8,
       6,    11,    38,  2142,  2606,  2606,  2606,    21,  -821,   105,
    -821,  -821,   -48,  -821,  -821,  -821,  -821,   154,   255,  -821,
     310,  -821,  -821,  -821,  -821,  -821,  -821,  -821,  -821,   156,
     176,  -821,  -821,  -821,  -821,   180,   214,   223,   226,  3479,
     263,   269,   279,   293,   296,   341,   351,   357,   373,   383,
     394,   396,   402,   408,   410,   416,   418,   420,   454,   466,
     477,   491,   499,   510,   516,   534,   542,   546,   561,   569,
     570,   577,   578,   583,   585,   586,   587,   589,   593,   594,
     614,   617,   622,   623,   627,   628,   629,   630,   631,   639,
     642,   643,   644,   647,   648,   649,   658,   660,   661,   664,
     665,   666,   667,   668,   676,   677,   680,   682,   683,   684,
     685,   686,   687,   688,   689,   690,   693,   694,  3479,  3479,
     199,  -821,   434,  -821,  -821,  -821,  -821,  2606,   311,  -821,
     154,   255,   478,  -821,  3479,  -821,  2606,  -821,   653,  3479,
    3834,  -821,  -821,  -821,  -821,  -821,    83,    51,   124,   260,
     311,  -821,  3479,  -821,   311,  -821,  -821,  3479,  3834,   339,
     696,   574,   697,    12,  3479,   -45,   199,  3695,   698,   699,
     482,  3695,   199,  5321,   199,  5381,   700,   703,   596,  -821,
    -821,   758,   758,  -821,  -821,   692,  -821,  3479,  2606,  3479,
       3,  3695,   705,  -821,  -821,  -821,  -821,   706,  2606,  5395,
    -821,  3479,  -821,    -3,   707,  -821,  -821,  3479,  3291,  -821,
    -821,  3695,  -821,  -821,   311,     0,     0,  -821,   771,   771,
     771,  2336,  2606,   381,   708,   311,   -30,   -13,  -821,  -821,
     766,  3479,  3479,  3479,  3479,  2606,  -821,  -821,  -821,  3479,
    3479,   625,  3479,  3479,  3479,  3479,  1948,  2142,   273,   273,
    3479,  3479,  3479,  3479,  3479,  3479,  3479,  3479,  3479,  3479,
    3479,  3479,  2142,  3479,  3479,  3479,  3479,  3479,  3479,  3479,
    3479,  2529,  2606,  2606,  2606,  2606,  2606,  3479,  3479,  3479,
    2722,  3479,  2606,  3479,  2606,  3479,  2606,  2606,   411,  1405,
    1486,  2413,  2606,  2606,  2606,  2606,  2606,  2606,  2606,  2606,
    2142,  2606,  -821,  -821,  2606,  3479,  2606,  2606,  2606,  2606,
    2606,   710,   711,  2606,   771,  2606,   771,  2606,  2606,  2606,
     734,    13,   305,  2606,  2606,  2606,  2606,  2606,  2606,  2606,
    -821,  -821,  -821,  3479,  3479,  3479,  3479,  3479,  3479,  3479,
    3479,  3479,  3479,  3479,  -141,  -821,  3695,   712,   311,   714,
     778,  3695,   595,  -821,  -821,  -821,  -821,   716,   718,   721,
    -821,   722,   723,   726,  -821,   199,  3695,   727,  -821,   199,
    3695,   861,   615,   865,  3834,  3479,   728,  2606,  -821,  -821,
    3479,   199,   756,    98,   735,    17,  -821,   911,  -821,  -821,
     303,  3479,  3479,  -821,  -821,    76,  -821,  -821,    55,  5409,
     311,  3695,   276,  3555,  3479,   311,  3479,  -821,   -45,  -821,
    -821,  3479,  2606,  -821,  3479,    -3,  3479,  3479,   737,   748,
     749,   757,  -821,  1538,   -58,  3479,  3479,  3479,  3479,  3834,
     759,    -3,    -3,  3695,   311,   472,   733,   754,  5449,  5463,
    1612,  5477,  5491,  5537,   760,    28,   761,   762,   765,   767,
     768,   770,   763,   773,    -3,  5551,  1637,  1966,  2160,  2933,
    3117,   793,  3305,   863,  3710,  3880,   772,  4049,  4212,  4226,
    4243,  4275,  4289,  4303,  5619,  -821,  4317,   -40,   -10,    16,
     196,    31,  5633,  5647,   951,  -821,  4371,  4385,    32,  4445,
     -83,  4459,    40,    49,  -821,    67,  -821,   101,  -821,   111,
    -821,   171,   172,   177,   242,   241,   247,   244,   294,   308,
     352,   774,   -82,   775,   777,   328,  4473,   336,   -57,   348,
     398,   473,  -821,  -821,   484,  -136,   520,    59,   531,   337,
     342,  -821,  -821,   311,   311,   311,   311,   311,   311,  -821,
    3479,  3479,   659,   331,   370,   405,   438,   271,  -821,   -73,
     -73,   734,   734,  -821,  -821,  -821,  3834,  -821,  -821,  3479,
    -821,  -821,  -821,  -821,    41,    41,  -821,  -821,   124,  -821,
    -821,   260,  3479,  -821,   887,  -821,  -821,  -821,  -821,  -821,
    -821,  -821,  -821,   452,  5679,  3479,   -29,  4513,  2799,  -821,
    -821,  3479,  3479,  -821,  -821,  3479,  -821,   507,   779,   780,
     782,   783,  5693,  5707,   784,   790,  -821,  -821,  -821,  3479,
     867,   884,  -821,   549,  5721,  3695,  -821,  -821,   550,  -821,
    3479,  5775,  5789,  -821,  3479,  3479,  3479,  -821,  -821,   199,
    3695,   199,  3695,  5849,  5863,  -821,  3479,  3479,  3479,  -821,
    -821,  -821,  -821,  -821,  3479,  3479,  -821,  3479,  3479,  3479,
    -821,  2606,  -821,  3658,  -821,   794,   795,  -821,  -821,  3479,
    3479,  3479,  3479,  -821,  -821,  -821,  -821,  -821,  3479,  -821,
    -821,  3479,  -821,  -821,  -821,  -821,  -821,  -821,  -821,  -821,
    -821,  -821,  -821,  3479,  -821,  -821,  3479,  3479,  3479,  -821,
    3479,  3479,  2606,  -821,  -821,  -821,  -821,  -821,  3479,  -821,
    -821,  -821,  -821,  -821,  -821,  -821,  -821,  -821,  -821,  -821,
    2606,  2606,  -821,  -821,  -821,  -821,  -821,  2606,  -821,  -821,
    -821,  -821,  -821,  -821,  3479,  -821,  3479,  3479,  3479,   986,
    2606,  -821,   986,  2606,  -821,  2606,  -821,  -821,   625,  6115,
    3479,    50,  3695,  -821,   799,  -821,   800,   801,   803,  -821,
     804,   805,  -821,  -821,  -821,   607,  3834,  -821,  -821,  -821,
    3479,  5877,  2606,   937,  -821,  2606,   311,   199,   756,  5917,
     507,   507,  4527,   807,   808,  -821,   810,  -821,  -821,  -821,
    -821,  3479,  3479,  -821,  -821,  5931,  2142,  2142,  2606,  2606,
    2606,  -821,  3479,  3479,   809,  4541,  4555,   965,  2606,  2606,
    3695,    -3,  -821,   811,  4601,  4615,  4683,  4697,  4711,   358,
     812,   -14,  -821,  -821,  4743,  4757,   813,    70,  4771,  4785,
    4839,  4853,  4913,  1332,  4927,  4941,    19,  4981,    58,    73,
     376,  4995,  5945,  5959,  5009,   147,   384,   178,   388,   412,
      97,  -821,  -821,  -821,    41,    41,  -821,  -821,  -821,  -821,
    3479,   963,   973,   969,  5023,  3479,   413,   822,    88,  -821,
    3479,  -821,  -821,  -821,  -821,  -821,  -821,   824,   825,  3695,
    3695,  2606,  -821,  -821,   311,   311,   566,  6005,  3695,  -821,
     942,   955,  3479,   958,   582,   311,  3479,   717,  -821,  -821,
    -821,  -821,  -821,  -821,  -821,  2606,  -821,  -821,  -821,  -821,
    3479,  -821,  -821,  -821,  -821,  -821,  3479,  -821,  -821,  -821,
    2606,  -821,  -821,  3479,  -821,  3479,  -821,  -821,  -821,  2606,
    3479,  -821,  2606,  -821,  -821,  2606,  -821,  -821,  -821,  3479,
    -821,  -821,  -821,  -821,  -821,   995,   691,  5069,   976,  3479,
    2606,  5083,   507,   849,   850,   507,  -821,  -821,   311,  2606,
    2606,  2606,  2606,  5151,  2606,  3479,  -821,   852,   853,   195,
    -821,   446,  6019,  5165,   457,  5179,  5211,   463,  5225,   475,
     481,   281,  3834,  4172,  3479,  1001,  -821,   855,  -821,   860,
    6087,   486,  -821,  -821,  -821,  -821,  -821,   311,   311,   311,
     311,   980,   311,  3695,   864,   866,   717,  -821,  -821,  3479,
    -821,  -821,  -821,  -821,  -821,  -821,  -821,  -821,  3479,  -821,
     969,  1022,   616,  3834,  -821,  2606,  3479,  3479,  -821,   911,
    2606,  -821,  -821,  -821,  3834,  5239,  3695,  3834,  -821,  -821,
     969,   624,   100,  6101,  5253,   507,   311,    35,  -821,   969,
    3834,  -821,  -821,  -821,  -821,  -821,  -821,  -821,  2606,  -821,
    3479,  -821,  -821,  -821,  -821,  -821,   709,   969,   521,  5307,
    -821,  -821,  -821,  -821,  -821,  -821,  1058,   995,  -821,  -821,
    -821,  -821,  -821
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   118,     0,     0,     0,   326,     0,     0,     0,   112,
     349,   384,   389,    17,     0,     0,     0,     0,    30,    32,
     327,     0,   311,   311,     0,   328,    24,    26,   364,   376,
       0,   457,    55,    67,     0,   109,   110,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,   119,
     120,     0,   100,     0,     0,     0,     0,     0,     0,     0,
       0,   101,     0,     0,     0,     0,     0,     0,     2,     9,
      16,     8,     0,    11,    45,    47,    13,    28,    29,    27,
       0,    19,    20,    23,    22,    21,    34,    35,   299,   207,
     140,   300,   301,   302,   143,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   153,     0,
       0,     0,     0,     0,     0,     0,   266,   269,   272,   275,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   168,
     170,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,     0,   220,   201,   206,   142,     0,     4,     5,
       0,     0,     0,     1,     0,   311,     0,   311,     0,     0,
      15,   304,   303,    36,    37,    44,     0,     0,     0,     0,
      18,    49,   313,    50,    48,   329,    25,     0,    15,   408,
       0,   461,     0,     0,   437,   453,    69,    68,     0,     0,
      70,   111,    60,     0,    62,     0,   429,   431,    63,   427,
     433,     0,     0,   434,   296,    64,    66,     0,    96,     0,
       0,   472,     0,    93,    98,    86,    46,     0,     0,     0,
      74,     0,    57,    79,     0,    95,    94,     0,     0,   121,
     122,    99,    12,    14,   113,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,   114,     0,     0,    51,     7,
       0,     0,     0,     0,     0,     0,   318,   311,   311,     0,
       0,   192,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   311,   311,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     213,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,   190,   188,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,   186,     0,   123,     0,
       0,   385,     9,    38,    39,    40,    42,   332,   333,    31,
     330,   338,   339,    33,   336,   316,   317,   312,   314,   369,
     368,     0,     9,     0,    15,     0,     0,     0,   458,   459,
       0,   440,   442,    52,     0,     0,    56,   455,   311,   311,
       0,     0,     0,   311,   311,     0,   298,   297,     0,     0,
      97,   471,     0,     0,     0,    73,     0,    78,   453,   130,
     129,     0,     0,    75,     0,    81,     0,     0,   138,     0,
       0,     0,   102,     0,     0,     0,     0,     0,     0,    15,
       0,     0,     0,   187,   128,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   246,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   154,     0,     0,     0,     0,
       0,     0,     0,     0,   267,     0,   270,     0,   273,     0,
     276,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,   171,     0,     0,     0,     0,     0,     0,
       0,   145,   221,   215,   217,   219,   216,   218,   214,   144,
       0,     0,   194,   196,   198,   195,   197,   193,   212,   209,
     208,   210,   211,   309,   310,   350,    15,   396,   394,     0,
     395,   391,   393,   390,     0,     0,   311,   311,     0,   311,
     311,     0,     0,   366,   370,   383,   381,   382,   379,   378,
     380,   377,   398,     9,     0,     0,     0,     0,     0,   438,
      53,    54,     0,   445,   447,     0,   456,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   428,   435,   436,     0,
       0,     0,   133,   132,   136,   224,    58,    76,    89,    80,
       0,     0,     0,   311,     0,     0,     0,   103,   104,   105,
     106,   107,   108,     0,     0,    10,     0,     0,     0,   324,
     325,   319,   288,   182,     0,     0,   279,     0,     0,     0,
     289,     0,   290,     0,   283,     0,     0,   202,   203,     0,
       0,     0,     0,   225,   226,   227,   228,   229,     0,   230,
     232,     0,   233,   235,   236,   199,   242,   243,   237,   239,
     240,   241,   238,     0,   245,   250,     0,     0,     0,   249,
       0,     0,     0,   150,   155,   156,   251,   180,     0,   252,
     181,   157,   158,   265,   268,   271,   274,   161,   159,   160,
       0,     0,   162,   258,   163,   264,   263,     0,   172,   259,
     164,   260,   165,   262,     0,   166,     0,     0,     0,     0,
       0,   175,     0,     0,   177,     0,   295,   185,   191,   189,
       0,     9,   392,   473,    41,   475,    43,     0,     0,   331,
       0,     0,   337,   315,   367,   373,    15,   410,   411,   409,
       0,     0,     0,   462,   460,     0,   443,   441,   442,     0,
       0,     0,     0,   423,   425,   454,   420,   305,   307,   311,
     311,     0,     0,   430,   432,    71,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
      87,     0,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   222,   223,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   388,   387,   386,     0,     0,   334,   335,   340,   341,
       0,     0,     0,   399,     0,     0,     0,     0,     0,   439,
       0,   446,   448,   449,   311,   311,   421,     0,     0,    59,
      61,     0,   134,   135,   131,   137,    90,    83,    84,   139,
       0,     0,     0,     0,   116,   117,     0,   342,   277,   278,
     280,   281,   282,   291,   292,     0,   293,   204,   205,   178,
       0,   231,   234,   244,   146,   147,     0,   149,   247,   248,
       0,   151,   253,     0,   254,     0,   256,   173,   167,     0,
       0,   184,     0,   285,   174,     0,   287,   176,   200,     0,
     474,   476,   371,   374,   365,   414,   464,     0,   463,     0,
       0,     0,     0,     0,     0,     0,   306,   308,    72,     0,
       0,     0,     0,     0,     0,     0,    88,   345,   346,     0,
     343,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   360,    15,   118,     0,   412,   468,     0,   465,     0,
       0,     0,   451,   450,   424,   426,   422,    91,    82,   126,
     127,     0,   125,   115,     0,     0,     0,   320,   294,     0,
     148,   152,   255,   257,   261,   183,   284,   286,     0,   351,
     372,     9,   418,    15,   400,     0,     0,     0,   444,   455,
       0,   347,   348,   344,    15,     0,   361,    15,   419,   415,
     413,     0,     0,     0,     0,     0,   124,     9,   179,   352,
      15,   407,   404,   405,   406,   402,   403,   401,     0,   469,
       0,   466,   452,   323,   322,   321,     0,   416,     0,     0,
     355,   357,   358,   359,   354,   356,   362,   414,   470,   467,
     363,   353,   417
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -821,  -821,  -821,  -198,  -821,    29,   575,  -821,  -821,  -821,
    -821,  -821,  -821,  -821,  1010,  -258,  -821,  -821,  -187,   736,
    -821,  1012,    -2,  -821,  -821,   764,  -301,   -43,  -821,   609,
     -39,    -9,  -821,   131,   146,    85,  -821,  -821,   444,  1072,
    -821,  -821,  -821,  -821,  -821,  -821,  -821,   451,  -821,   450,
    -821,    42,  -821,  -821,  -821,  -821,  -821,  -821,  -821,  -821,
    -821,  -821,  -821,   189,  -821,  -821,  -821,  -821,  -821,  -821,
    -821,  -821,  -821,  -821,  -821,  -821,  -821,  -821,  -821,  -821,
    -821,  -821,  -821,  -821,  -821,  -821,  -821,  -821,   -26,  -821,
    -821,  -821,  -820,  -821,  -821,  -821,   652,  -821,  -821,   282,
     650,  -821,  -821,  -821,  -821,  -821,    33,  -821,    26,  -821,
    -821
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,    68,    69,   290,    70,    71,   208,   209,   624,
     625,   225,   468,    72,    73,   471,    74,    75,   479,   180,
     181,    76,   259,   601,   600,   510,   511,   260,   183,   243,
     184,   203,   230,   185,   186,   211,   212,   427,   428,    79,
     495,   863,  1084,  1115,   701,    80,   419,   420,   423,   424,
    1019,  1020,    81,   198,   800,  1087,  1116,  1126,  1069,  1131,
      82,   217,   634,   431,   815,  1032,   912,  1033,    83,   218,
     641,    84,   199,   616,   903,    85,   200,   623,    86,   433,
     816,   995,  1091,  1107,    87,   434,   819,  1074,  1035,  1100,
    1127,  1089,   835,  1005,   836,   238,   239,   245,   443,   649,
     446,   830,   831,  1002,  1079,   447,   657,   224,   252,   804,
     806
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     182,   244,   412,   399,   263,   264,   204,   205,   513,   469,
     921,   922,   469,   444,   462,   207,   438,   476,   477,   439,
     432,   653,   228,   229,   654,     7,     8,   220,   219,   221,
     222,   227,   246,   189,   231,   233,   235,   194,   196,   193,
     251,   251,   251,   291,   292,   201,    88,   389,   202,   271,
      91,    92,    93,   240,   591,   293,   277,   790,    88,   791,
    1113,   251,    91,    92,    93,   667,   901,     7,     8,   256,
     257,   415,   416,   383,   384,   385,   386,   387,   388,  1114,
     236,   237,   469,   383,   384,   385,   386,   387,   388,   284,
      20,   216,   480,   481,   902,    25,   288,   301,   383,   384,
     385,   386,   387,   388,   270,   389,   389,   215,   213,   989,
     758,   777,   759,   778,   391,   392,   402,   403,   413,   414,
      53,   393,   394,   395,   396,   397,   398,   399,   417,   418,
     389,   389,    77,   391,   392,   190,   784,   688,   785,   258,
     393,   394,   395,   396,   397,   398,   399,    78,   389,   289,
     191,   445,    58,    59,    60,   745,   195,   197,   389,   389,
     391,   392,   278,   487,   822,   223,   823,   393,   394,   395,
     396,   397,   398,   399,   389,   389,   380,   382,   389,   955,
     488,   956,  1043,   746,   190,  1046,   279,   585,   389,   587,
     470,   389,   406,   470,    58,    59,    60,   411,   190,   191,
     280,   389,   456,   457,   389,   281,   440,   389,   591,   747,
     426,   655,   970,   191,   971,   430,   389,   680,   467,   389,
     389,   711,   442,   712,   473,   475,   749,   756,   389,   294,
     241,   242,   282,   697,   698,   761,   643,   389,   400,   401,
     402,   403,   241,   242,   762,   459,   389,   461,   490,   491,
     492,   973,   793,   974,   794,   389,   721,   400,   401,   402,
     403,   389,   763,   470,   421,   422,   975,   514,   976,   383,
     384,   385,   386,   387,   388,  1112,   389,   508,   509,   483,
     407,  1000,   409,   591,   400,   401,   402,   403,   389,   389,
     650,   651,   493,  1108,  1068,  1109,   764,   498,   499,   389,
     500,   501,   502,   503,   251,   251,   765,   660,   661,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     251,   527,   528,   529,   530,   531,   532,   533,   534,   536,
     295,    77,   506,   507,   296,   542,   543,   544,   546,   547,
     982,   549,   983,   551,   391,   392,    78,   399,   526,    77,
     195,   393,   394,   395,   396,   397,   398,   399,   251,   389,
     389,   670,   671,   576,    78,   389,   766,   767,   391,   392,
     197,   985,   768,   986,   297,   393,   394,   395,   396,   397,
     398,   399,   496,   497,   389,  -397,   571,   389,  1056,   748,
    1057,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   391,   392,   396,   397,   398,   399,   298,   393,
     394,   395,   396,   397,   398,   399,    90,   299,   801,   244,
     300,    94,   383,   384,   385,   386,   387,   388,   677,   389,
     389,   679,   389,   644,   770,   389,   265,   769,   647,   772,
     771,   394,    96,   396,   397,   398,   399,   573,   574,   662,
     663,   383,   384,   385,   386,   387,   388,   302,   400,   401,
     402,   403,   674,   303,   675,   266,   267,   268,   400,   401,
     402,   403,   269,   304,   681,   682,   699,   700,   390,   397,
     398,   399,   389,   690,   692,   693,   694,   305,   895,   773,
     306,   897,   400,   401,   402,   403,   389,   391,   392,   389,
     592,   817,   818,   774,   393,   394,   395,   396,   397,   398,
     399,   833,   834,   398,   399,   108,   389,   109,   400,   401,
     402,   403,   405,   781,   389,   389,   400,   401,   402,   403,
     389,   783,   796,   658,   659,   307,   389,   797,   664,   665,
     389,   786,   131,   132,   133,   308,   389,   775,   137,   138,
     139,   309,   141,   953,   143,   144,   145,   400,   401,   402,
     403,   150,   151,   152,   389,    77,   155,   310,   157,   389,
     159,   977,   389,   161,   485,   163,   389,   311,   165,   984,
      78,   167,   168,   987,   169,   170,   389,   172,   312,   174,
     313,   787,   400,   401,   402,   403,   314,   177,   798,   799,
     389,   389,   315,   946,   316,   187,   554,   988,   998,   617,
     317,   618,   318,   619,   319,   803,   805,   802,   913,   960,
      77,   400,   401,   402,   403,   400,   401,   402,   403,   635,
     426,   636,   436,   637,   389,    78,   620,   851,  1101,   621,
    1102,  1058,  1103,   821,   622,   389,   910,   911,   320,   828,
     829,   389,  1061,   832,   861,   862,   638,   410,  1064,   639,
     321,   389,  1088,   389,   640,  1104,   788,   845,  1105,   389,
    1066,   322,   389,  1106,   389,   450,  1067,   789,   876,   391,
     392,  1078,   855,   856,   857,   323,   393,   394,   395,   396,
     397,   398,   399,   324,   860,   393,   394,   395,   396,   397,
     398,   399,   864,   865,   325,   866,   867,   868,   389,   389,
     326,   807,   808,   792,   810,   811,  1128,   874,   875,   389,
     877,  1017,  1018,  1120,   795,  1121,   878,  1122,   327,   879,
     394,   395,   396,   397,   398,   399,   328,   389,   389,   188,
     329,   880,   848,   850,   881,   882,   883,    77,   884,   885,
    1123,  1036,  1037,  1124,   389,   330,   887,   210,  1125,  1009,
     214,    88,    78,   331,   332,    91,    92,    93,   854,   226,
     389,   333,   334,   232,   234,  1015,   478,   335,   250,   336,
     337,   338,   891,   339,   892,   893,   894,   340,   341,   455,
     274,   275,   276,     1,     2,     3,     4,     5,   900,   283,
     285,   286,   287,   400,   401,   402,   403,   648,   342,   489,
     399,   343,   400,   401,   402,   403,   344,   345,   914,   391,
     392,   346,   347,   348,   349,   350,   393,   394,   395,   396,
     397,   398,   399,   351,  1070,  1071,   352,   353,   354,   929,
     930,   355,   356,   357,   251,   251,   400,   401,   402,   403,
     937,   938,   358,   615,   359,   360,   391,   392,   361,   362,
     363,   364,   365,   393,   394,   395,   396,   397,   398,   399,
     366,   367,   932,   933,   368,  1090,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   458,  1097,   378,   379,  1099,
     435,   437,   448,   449,   453,   990,   991,   454,   463,   464,
     472,   486,  1117,  1016,   633,   582,   583,   613,   430,   614,
     626,   642,   627,   997,   628,   381,   629,   630,  1001,   631,
     632,   656,   645,   404,   927,   928,   391,   392,   702,   652,
     814,   683,   408,   393,   394,   395,   396,   397,   398,   399,
    1013,   684,   685,   400,   401,   402,   403,    77,   425,   703,
     686,   846,   696,   429,   713,   710,   719,   714,  1022,   715,
     441,   716,    78,   717,  1023,   718,   720,   735,   847,   776,
     779,  1025,   780,  1026,   837,   838,   839,   840,  1028,   843,
     400,   401,   402,   403,   460,   844,   728,  1031,   729,   872,
     873,   509,   904,   905,   465,   917,   906,  1040,   907,   908,
     909,   924,   925,   926,   939,   947,   993,   954,   959,  1003,
    1004,   994,    -9,  1053,   391,   392,   999,  1011,   484,  1006,
    1007,   393,   394,   395,   396,   397,   398,   399,   391,   392,
    1012,   494,  1072,  1014,  1039,   393,   394,   395,   396,   397,
     398,   399,   505,  1034,  1044,  1045,  1054,  1055,  1073,  1075,
     400,   401,   402,   403,  1076,  1080,   731,  1085,   732,  1081,
    -375,  1082,  1130,   272,   695,   273,  1086,   668,   537,   538,
     539,   540,   541,   512,  1093,  1094,   813,   192,   548,   809,
     550,   812,   552,   553,   555,   557,   559,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   572,  1083,   992,
     575,  1132,   577,   578,   579,   580,   581,   666,  1119,   584,
     919,   586,  1095,   588,   589,   590,     0,     0,   676,   593,
     594,   595,   596,   597,   598,   599,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   400,   401,
     402,   403,     0,     0,   752,     0,   753,     0,     0,     0,
       0,     0,   400,   401,   402,   403,     0,     0,   942,     0,
     943,     0,     0,    77,    77,     0,     0,     0,     0,     0,
       0,     0,     0,   646,     0,     0,     0,     0,    78,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,     0,    91,    92,    93,    94,     0,     0,   673,
       0,     0,     0,     0,    77,     0,     0,     0,   678,     0,
       0,     0,     0,     0,     0,    77,    95,    96,    77,    78,
       0,   689,   691,     0,     0,     0,     0,     0,     0,     0,
      78,    77,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,     0,     0,   105,
       0,     0,     0,     0,   253,     0,     0,     0,     0,     0,
       0,     0,   254,     0,     0,     0,   106,   107,     0,     0,
     108,     0,   109,     0,     0,   255,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,     0,   160,   161,   162,
     163,     0,   164,   165,     0,   166,   167,   168,     0,   169,
     170,   171,   172,   173,   174,   175,     0,     0,   425,     0,
       0,   176,   177,   178,     0,     0,     0,     0,     0,     0,
     179,     0,   249,     0,   826,     0,     0,   827,     0,     0,
       0,     0,     0,     0,     0,   391,   392,     0,     0,     0,
       0,     0,   393,   394,   395,   396,   397,   398,   399,     0,
      90,     0,     0,     0,     0,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   869,     0,   871,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   886,     0,
       0,    90,     0,     0,     0,     0,    94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   888,   889,     0,   108,
       0,   109,     0,   890,     0,     0,     0,    96,     0,   400,
     401,   402,   403,     0,     0,   966,   896,   967,     0,   898,
       0,   899,     0,     0,     0,     0,   131,   132,   133,     0,
       0,     0,   137,   138,   139,     0,   141,     0,   143,   144,
     145,     0,     0,     0,     0,   150,   151,   152,   916,     0,
     155,   918,   157,     0,   159,     0,     0,   161,     0,   163,
       0,     0,   165,     0,     0,   167,   168,     0,   169,   170,
       0,   172,     0,   174,   934,   935,   936,     0,     0,     0,
     108,   177,   109,     0,   944,   945,     0,     0,     0,   187,
     556,   391,   392,     0,     0,     0,     0,     0,   393,   394,
     395,   396,   397,   398,   399,     0,     0,   131,   132,   133,
       0,     0,     0,   137,   138,   139,     0,   141,     0,   143,
     144,   145,     0,     0,     0,     0,   150,   151,   152,     0,
       0,   155,     0,   157,     0,   159,   429,     0,   161,     0,
     163,     0,     0,   165,     0,     0,   167,   168,     0,   169,
     170,     0,   172,     0,   174,     0,     0,  1008,     0,     0,
       0,     0,   177,     0,     0,   391,   392,     0,     0,     0,
     187,   558,   393,   394,   395,   396,   397,   398,   399,     0,
       0,  1021,     0,     0,     0,     0,     0,     0,     0,     0,
     391,   392,     0,     0,     0,     0,  1024,   393,   394,   395,
     396,   397,   398,   399,     0,  1027,     0,     0,  1029,     0,
       0,  1030,     0,     0,     0,   400,   401,   402,   403,     0,
       0,     0,     0,   687,     0,     0,  1041,     0,     0,     0,
       0,     0,     0,     0,     0,  1047,  1048,  1049,  1050,     0,
    1052,     0,     0,     0,     0,     0,     0,    88,    89,    90,
       0,    91,    92,    93,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   400,
     401,   402,   403,     0,     0,     0,     0,   706,     0,     0,
       0,  1092,     0,     0,     0,     0,  1096,    97,    98,    99,
     100,   101,   102,   103,   400,   401,   402,   403,     0,     0,
       0,     0,   723,     0,   104,     0,     0,   105,     0,     0,
       0,     0,   247,     0,  1118,     0,     0,     0,     0,     0,
     248,     0,     0,     0,   106,   107,     0,     0,   108,     0,
     109,     0,     0,     0,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,     0,   160,   161,   162,   163,     0,
     164,   165,     0,   166,   167,   168,     0,   169,   170,   171,
     172,   173,   174,   175,     0,     0,     0,     0,     0,   176,
     177,   178,     0,     0,     0,     0,     0,     0,   179,     0,
     249,    88,    89,    90,     0,    91,    92,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   391,
     392,   105,     0,     0,     0,     0,   393,   394,   395,   396,
     397,   398,   399,     0,   504,     0,     0,     0,   106,   107,
       0,     0,   108,     0,   109,     0,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,     0,   160,
     161,   162,   163,     0,   164,   165,     0,   166,   167,   168,
       0,   169,   170,   171,   172,   173,   174,   175,     0,     0,
       0,     0,     0,   176,   177,   178,     0,     0,     0,     0,
       0,     0,   179,     0,   249,    88,    89,    90,     0,    91,
      92,    93,    94,   400,   401,   402,   403,     0,     0,     0,
       0,   724,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   104,   391,   392,   105,     0,     0,     0,     0,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,     0,   106,   107,     0,     0,   108,     0,   109,     0,
       0,     0,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,     0,   160,   161,   162,   163,     0,   164,   165,
       0,   166,   167,   168,     0,   169,   170,   171,   172,   173,
     174,   175,     0,     0,     0,     0,     0,   176,   177,   178,
       0,     0,     0,     0,     0,     0,   179,     0,   249,    88,
      89,    90,     0,    91,    92,    93,    94,   400,   401,   402,
     403,     0,     0,     0,     0,   725,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,     0,    90,   105,
       0,     0,     0,    94,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   106,   107,     0,     0,
     108,     0,   109,     0,    96,     0,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,     0,   160,   161,   162,
     163,     0,   164,   165,     0,   166,   167,   168,     0,   169,
     170,   171,   172,   173,   174,   175,     0,   108,     0,   109,
       0,   176,   177,   178,     0,     0,     0,     0,     0,     0,
     179,   482,    88,    89,    90,     0,    91,    92,    93,    94,
       0,     0,     0,     0,   131,   132,   133,     0,     0,     0,
     137,   138,   139,     0,   141,     0,   143,   144,   145,    95,
      96,     0,     0,   150,   151,   152,     0,     0,   155,     0,
     157,     0,   159,     0,     0,   161,     0,   163,     0,     0,
     165,     0,     0,   167,   168,     0,   169,   170,     0,   172,
       0,   174,    97,    98,    99,   100,   101,   102,   103,   177,
       0,     0,     0,     0,     0,     0,     0,   187,   560,   104,
       0,    90,   105,     0,     0,     0,    94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,   108,     0,   109,     0,    96,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,     0,
     160,   161,   162,   163,     0,   164,   165,     0,   166,   167,
     168,     0,   169,   170,   171,   172,   173,   174,   175,     0,
     108,     0,   109,     0,   176,   177,   178,     0,     0,     0,
       0,     0,     0,   179,   535,    88,    89,    90,     0,    91,
      92,    93,    94,     0,     0,     0,     0,   131,   132,   133,
       0,     0,     0,   137,   138,   139,     0,   141,     0,   143,
     144,   145,    95,    96,     0,     0,   150,   151,   152,     0,
       0,   155,     0,   157,     0,   159,     0,     0,   161,     0,
     163,     0,     0,   165,     0,     0,   167,   168,     0,   169,
     170,     0,   172,     0,   174,    97,    98,    99,   100,   101,
     102,   103,   177,     0,     0,     0,     0,     0,     0,     0,
     187,     0,   104,     0,    90,   105,     0,     0,     0,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,   108,     0,   109,     0,
      96,     0,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,     0,   160,   161,   162,   163,     0,   164,   165,
       0,   166,   167,   168,     0,   169,   170,   171,   172,   173,
     174,   175,     0,   108,     0,   109,     0,   176,   177,   178,
       0,     0,     0,     0,     0,     0,   179,   545,    88,    89,
      90,     0,    91,    92,    93,    94,     0,   261,     0,     0,
     131,   132,   133,     0,     0,     0,   137,   138,   139,     0,
     141,     0,   143,   144,   145,    95,    96,     0,     0,   150,
     151,   152,     0,     0,   155,     0,   157,     0,   159,     0,
       0,   161,     0,   163,     0,     0,   165,     0,   262,   167,
     168,     0,   169,   170,     0,   172,     0,   174,    97,    98,
      99,   100,   101,   102,   103,   177,     0,     0,     0,     0,
       0,     0,     0,   825,     0,   104,   391,   392,   105,     0,
       0,     0,     0,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,     0,   106,   107,     0,     0,   108,
       0,   109,     0,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,     0,   160,   161,   162,   163,
       0,   164,   165,     0,   166,   167,   168,     0,   169,   170,
     171,   172,   173,   174,   175,     0,     0,     0,     0,     0,
     176,   177,   178,     0,     0,     0,    88,    89,    90,   179,
      91,    92,    93,    94,     0,     0,     0,     0,     0,     0,
     400,   401,   402,   403,     0,     0,     0,     0,   726,     0,
       0,     0,     0,    95,    96,     0,     0,   206,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    97,    98,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,     0,
     391,   392,     0,   104,     0,     0,   105,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,   108,     0,   109,
       0,     0,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,     0,   160,   161,   162,   163,     0,   164,
     165,     0,   166,   167,   168,     0,   169,   170,   171,   172,
     173,   174,   175,     0,     0,     0,     0,     0,   176,   177,
     178,     0,     0,     0,    88,    89,    90,   179,    91,    92,
      93,    94,     0,   474,   400,   401,   402,   403,     0,     0,
       0,     0,   727,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,     0,   391,   392,
       0,   104,     0,     0,   105,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,   108,     0,   109,     0,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,     0,   160,   161,   162,   163,     0,   164,   165,     0,
     166,   167,   168,     0,   169,   170,   171,   172,   173,   174,
     175,     0,     0,     0,     0,     0,   176,   177,   178,     0,
       0,     0,    88,    89,    90,   179,    91,    92,    93,    94,
       0,     0,   400,   401,   402,   403,     0,     0,     0,     0,
     730,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      96,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
      90,     0,   105,     0,     0,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,   108,     0,   109,    96,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,     0,
     160,   161,   162,   163,     0,   164,   165,     0,   166,   167,
     168,   672,   169,   170,   171,   172,   173,   174,   175,   108,
       0,   109,     0,    90,   176,   177,   178,     0,    94,     0,
       0,     0,     0,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131,   132,   133,    96,
       0,     0,   137,   138,   139,     0,   141,     0,   143,   144,
     145,     0,     0,     0,     0,   150,   151,   152,     0,     0,
     155,     0,   157,     0,   159,     0,     0,   161,     0,   163,
       0,     0,   165,     0,     0,   167,   168,     0,   169,   170,
       0,   172,     0,   174,     0,     0,     0,     0,     0,     0,
       0,   177,     0,     0,     0,     0,     0,     0,     0,   187,
       0,     0,     0,     0,   870,     0,     0,     0,   391,   392,
       0,     0,   108,     0,   109,   393,   394,   395,   396,   397,
     398,   399,     0,   391,   392,     0,     0,     0,     0,     0,
     393,   394,   395,   396,   397,   398,   399,     0,     0,   131,
     132,   133,     0,     0,     0,   137,   138,   139,     0,   141,
       0,   143,   144,   145,     0,     0,     0,     0,   150,   151,
     152,     0,     0,   155,     0,   157,     0,   159,     0,     0,
     161,     0,   163,     0,     0,   165,     0,     0,   167,   168,
       0,   169,   170,     0,   172,     0,   174,     0,     7,     8,
       9,     0,     0,     0,   177,    10,     0,     0,     0,    11,
       0,    12,   187,    13,    14,    15,    16,    17,  -326,     0,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,    28,     0,     0,     0,     0,    29,     0,     0,    30,
       0,     0,   400,   401,   402,   403,    31,    32,    33,    34,
      35,    36,     0,     0,     0,    37,    38,   400,   401,   402,
     403,     0,     0,     0,     0,   733,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,    44,     0,     0,     0,
       0,     0,    45,    46,    47,  -118,  -118,    48,    49,    50,
       0,    51,    52,    53,     0,     0,    54,  -118,     0,    55,
       0,    56,    57,   391,   392,     0,     0,     0,     0,     0,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,     0,     0,     0,     0,    58,    59,    60,     0,     0,
       0,     0,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      62,     0,     0,     0,    63,     0,     0,     0,     0,    64,
       0,     0,    65,     0,     0,     0,    66,     7,     8,     9,
       0,     0,     0,     0,    10,     0,     0,     0,    11,    67,
      12,     0,    13,    14,    15,    16,    17,  -326,     0,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,    27,
      28,     0,     0,     0,     0,    29,   -15,   -15,    30,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,    35,
      36,     0,     0,     0,    37,    38,     0,   400,   401,   402,
     403,     0,     0,     0,     0,   734,     0,     0,     0,     0,
      39,    40,    41,    42,    43,    44,     0,     0,     0,     0,
       0,    45,    46,    47,     0,     0,    48,    49,    50,     0,
      51,    52,    53,     0,     0,    54,     0,     0,    55,     0,
      56,    57,   391,   392,     0,     0,     0,     0,     0,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,     0,     0,     0,
       0,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
       0,     0,     0,    63,     0,     0,     0,     0,    64,     0,
       0,    65,     0,     0,     0,    66,     7,     8,     9,     0,
       0,     0,     0,    10,     0,     0,     0,    11,    67,    12,
       0,    13,    14,    15,    16,    17,  -326,     0,    18,    19,
      20,    21,    22,    23,    24,    25,     0,    26,    27,    28,
     -15,     0,     0,     0,    29,   -15,     0,    30,     0,     0,
       0,     0,     0,     0,    31,    32,    33,    34,    35,    36,
       0,     0,     0,    37,    38,     0,   400,   401,   402,   403,
       0,     0,     0,     0,   736,     0,     0,     0,     0,    39,
      40,    41,    42,    43,    44,     0,     0,     0,     0,     0,
      45,    46,    47,     0,     0,    48,    49,    50,     0,    51,
      52,    53,     0,     0,    54,   391,   392,    55,     0,    56,
      57,     0,   393,   394,   395,   396,   397,   398,   399,   391,
     392,     0,     0,     0,     0,     0,   393,   394,   395,   396,
     397,   398,   399,    58,    59,    60,   391,   392,     0,     0,
      61,     0,     0,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,     0,     0,     0,     0,    62,     0,
       0,     0,    63,     0,     0,     0,     0,    64,   391,   392,
      65,     0,     0,     0,    66,   393,   394,   395,   396,   397,
     398,   399,   391,   392,     0,     0,     0,    67,     0,   393,
     394,   395,   396,   397,   398,   399,   391,   392,     0,     0,
       0,     0,     0,   393,   394,   395,   396,   397,   398,   399,
     391,   392,     0,     0,     0,     0,     0,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,     0,   400,
     401,   402,   403,     0,     0,     0,     0,   737,     0,     0,
       0,     0,     0,   400,   401,   402,   403,     0,     0,     0,
       0,   738,     0,     0,     0,     0,     0,     0,     0,     0,
     400,   401,   402,   403,   391,   392,     0,     0,   739,     0,
       0,   393,   394,   395,   396,   397,   398,   399,   391,   392,
       0,     0,     0,     0,     0,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,     0,     0,     0,     0,
     740,     0,     0,     0,     0,     0,   400,   401,   402,   403,
       0,     0,     0,     0,   741,     0,     0,     0,     0,     0,
     400,   401,   402,   403,     0,     0,     0,     0,   742,     0,
       0,     0,     0,     0,   400,   401,   402,   403,   391,   392,
       0,     0,   744,     0,     0,   393,   394,   395,   396,   397,
     398,   399,   391,   392,     0,     0,     0,     0,     0,   393,
     394,   395,   396,   397,   398,   399,   391,   392,     0,     0,
       0,     0,     0,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,     0,     0,     0,     0,   400,   401,
     402,   403,     0,     0,     0,     0,   754,     0,     0,     0,
       0,     0,   400,   401,   402,   403,   391,   392,     0,     0,
     755,     0,     0,   393,   394,   395,   396,   397,   398,   399,
     391,   392,     0,     0,     0,     0,     0,   393,   394,   395,
     396,   397,   398,   399,   391,   392,     0,     0,     0,     0,
       0,   393,   394,   395,   396,   397,   398,   399,   391,   392,
       0,     0,     0,     0,     0,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,     0,     0,     0,     0,
     757,     0,     0,     0,     0,     0,   400,   401,   402,   403,
       0,     0,     0,     0,   760,     0,     0,     0,     0,     0,
     400,   401,   402,   403,   391,   392,     0,     0,   782,     0,
       0,   393,   394,   395,   396,   397,   398,   399,   391,   392,
       0,     0,     0,     0,     0,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,     0,     0,     0,     0,
     400,   401,   402,   403,     0,     0,     0,     0,   824,     0,
       0,     0,     0,     0,   400,   401,   402,   403,     0,     0,
       0,     0,   923,     0,     0,     0,     0,     0,   400,   401,
     402,   403,     0,     0,     0,     0,   940,     0,     0,     0,
       0,     0,   400,   401,   402,   403,   391,   392,     0,     0,
     941,     0,     0,   393,   394,   395,   396,   397,   398,   399,
     391,   392,     0,     0,     0,     0,     0,   393,   394,   395,
     396,   397,   398,   399,   391,   392,     0,     0,     0,     0,
       0,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,     0,     0,     0,     0,   948,     0,     0,     0,
       0,     0,   400,   401,   402,   403,   391,   392,     0,     0,
     949,     0,     0,   393,   394,   395,   396,   397,   398,   399,
     391,   392,     0,     0,     0,     0,     0,   393,   394,   395,
     396,   397,   398,   399,   391,   392,     0,     0,     0,     0,
       0,   393,   394,   395,   396,   397,   398,   399,   391,   392,
       0,     0,     0,     0,     0,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,     0,     0,     0,     0,
     400,   401,   402,   403,     0,     0,     0,     0,   950,     0,
       0,     0,     0,     0,   400,   401,   402,   403,     0,     0,
       0,     0,   951,     0,     0,     0,     0,     0,   400,   401,
     402,   403,   391,   392,     0,     0,   952,     0,     0,   393,
     394,   395,   396,   397,   398,   399,   391,   392,     0,     0,
       0,     0,     0,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,     0,     0,     0,     0,   957,     0,
       0,     0,     0,     0,   400,   401,   402,   403,     0,     0,
       0,     0,   958,     0,     0,     0,     0,     0,   400,   401,
     402,   403,     0,     0,     0,     0,   961,     0,     0,     0,
       0,     0,   400,   401,   402,   403,   391,   392,     0,     0,
     962,     0,     0,   393,   394,   395,   396,   397,   398,   399,
     391,   392,     0,     0,     0,     0,     0,   393,   394,   395,
     396,   397,   398,   399,   391,   392,     0,     0,     0,     0,
       0,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,     0,     0,     0,     0,   400,   401,   402,   403,
       0,     0,     0,     0,   963,     0,     0,     0,     0,     0,
     400,   401,   402,   403,   391,   392,     0,     0,   964,     0,
       0,   393,   394,   395,   396,   397,   398,   399,   391,   392,
       0,     0,     0,     0,     0,   393,   394,   395,   396,   397,
     398,   399,   391,   392,     0,     0,     0,     0,     0,   393,
     394,   395,   396,   397,   398,   399,   391,   392,     0,     0,
       0,     0,     0,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,     0,     0,     0,     0,   965,     0,
       0,     0,     0,     0,   400,   401,   402,   403,     0,     0,
       0,     0,   968,     0,     0,     0,     0,     0,   400,   401,
     402,   403,   391,   392,     0,     0,   969,     0,     0,   393,
     394,   395,   396,   397,   398,   399,   391,   392,     0,     0,
       0,     0,     0,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,     0,     0,     0,     0,   400,   401,
     402,   403,     0,     0,     0,     0,   972,     0,     0,     0,
       0,     0,   400,   401,   402,   403,     0,     0,     0,     0,
     978,     0,     0,     0,     0,     0,   400,   401,   402,   403,
       0,     0,     0,     0,   981,     0,     0,     0,     0,     0,
     400,   401,   402,   403,   391,   392,     0,     0,   996,     0,
       0,   393,   394,   395,   396,   397,   398,   399,   391,   392,
       0,     0,     0,     0,     0,   393,   394,   395,   396,   397,
     398,   399,   391,   392,     0,     0,     0,     0,     0,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
       0,     0,     0,     0,  1038,     0,     0,     0,     0,     0,
     400,   401,   402,   403,   391,   392,     0,     0,  1042,     0,
       0,   393,   394,   395,   396,   397,   398,   399,   391,   392,
       0,     0,     0,     0,     0,   393,   394,   395,   396,   397,
     398,   399,   391,   392,     0,     0,     0,     0,     0,   393,
     394,   395,   396,   397,   398,   399,   391,   392,     0,     0,
       0,     0,     0,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,     0,     0,     0,     0,   400,   401,
     402,   403,     0,     0,     0,     0,  1051,     0,     0,     0,
       0,     0,   400,   401,   402,   403,     0,     0,     0,     0,
    1060,     0,     0,     0,     0,     0,   400,   401,   402,   403,
     391,   392,     0,     0,  1062,     0,     0,   393,   394,   395,
     396,   397,   398,   399,   391,   392,     0,     0,     0,     0,
       0,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,     0,     0,     0,     0,  1063,     0,     0,     0,
       0,     0,   400,   401,   402,   403,     0,     0,     0,     0,
    1065,     0,     0,     0,     0,     0,   400,   401,   402,   403,
       0,     0,     0,     0,  1098,     0,     0,     0,     0,     0,
     400,   401,   402,   403,   391,   392,     0,     0,  1111,     0,
       0,   393,   394,   395,   396,   397,   398,   399,   391,   392,
       0,     0,     0,     0,     0,   393,   394,   395,   396,   397,
     398,   399,   391,   392,     0,     0,     0,     0,     0,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
       0,     0,     0,     0,   400,   401,   402,   403,     0,     0,
       0,     0,  1129,     0,     0,     0,     0,     0,   400,   401,
     402,   403,   391,   392,   451,     0,     0,     0,     0,   393,
     394,   395,   396,   397,   398,   399,   391,   392,     0,     0,
       0,     0,     0,   393,   394,   395,   396,   397,   398,   399,
     391,   392,     0,     0,     0,     0,     0,   393,   394,   395,
     396,   397,   398,   399,   391,   392,     0,     0,     0,     0,
       0,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,     0,     0,   452,     0,     0,     0,     0,     0,
       0,     0,   400,   401,   402,   403,     0,     0,   466,     0,
       0,     0,     0,     0,     0,     0,   400,   401,   402,   403,
     391,   392,   669,     0,     0,     0,     0,   393,   394,   395,
     396,   397,   398,   399,   391,   392,     0,     0,     0,     0,
       0,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,     0,     0,     0,     0,   400,   401,   402,   403,
       0,     0,   704,     0,     0,     0,     0,     0,     0,     0,
     400,   401,   402,   403,     0,     0,   705,     0,     0,     0,
       0,     0,     0,     0,   400,   401,   402,   403,     0,     0,
     707,     0,     0,     0,     0,     0,     0,     0,   400,   401,
     402,   403,   391,   392,   708,     0,     0,     0,     0,   393,
     394,   395,   396,   397,   398,   399,   391,   392,     0,     0,
       0,     0,     0,   393,   394,   395,   396,   397,   398,   399,
     391,   392,     0,     0,     0,     0,     0,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,     0,     0,
     709,     0,     0,     0,     0,     0,     0,     0,   400,   401,
     402,   403,   391,   392,   722,     0,     0,     0,     0,   393,
     394,   395,   396,   397,   398,   399,   391,   392,     0,     0,
       0,     0,     0,   393,   394,   395,   396,   397,   398,   399,
     391,   392,     0,     0,     0,     0,     0,   393,   394,   395,
     396,   397,   398,   399,   391,   392,     0,     0,     0,     0,
       0,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,     0,     0,     0,     0,   400,   401,   402,   403,
       0,     0,   743,     0,     0,     0,     0,     0,     0,     0,
     400,   401,   402,   403,     0,     0,   750,     0,     0,     0,
       0,     0,     0,     0,   400,   401,   402,   403,   391,   392,
     751,     0,     0,     0,     0,   393,   394,   395,   396,   397,
     398,   399,   391,   392,     0,     0,     0,     0,     0,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
       0,     0,   820,     0,     0,     0,     0,     0,     0,     0,
     400,   401,   402,   403,     0,     0,   841,     0,     0,     0,
       0,     0,     0,     0,   400,   401,   402,   403,     0,     0,
     842,     0,     0,     0,     0,     0,     0,     0,   400,   401,
     402,   403,   391,   392,   849,     0,     0,     0,     0,   393,
     394,   395,   396,   397,   398,   399,   391,   392,     0,     0,
       0,     0,     0,   393,   394,   395,   396,   397,   398,   399,
     391,   392,     0,     0,     0,     0,     0,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,     0,     0,
       0,     0,   400,   401,   402,   403,     0,     0,   852,     0,
       0,     0,     0,     0,     0,     0,   400,   401,   402,   403,
     391,   392,   853,     0,     0,     0,     0,   393,   394,   395,
     396,   397,   398,   399,   391,   392,     0,     0,     0,     0,
       0,   393,   394,   395,   396,   397,   398,   399,   391,   392,
       0,     0,     0,     0,     0,   393,   394,   395,   396,   397,
     398,   399,   391,   392,     0,     0,     0,     0,     0,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
       0,     0,   858,     0,     0,     0,     0,     0,     0,     0,
     400,   401,   402,   403,     0,     0,   859,     0,     0,     0,
       0,     0,     0,     0,   400,   401,   402,   403,   391,   392,
     915,     0,     0,     0,     0,   393,   394,   395,   396,   397,
     398,   399,   391,   392,     0,     0,     0,     0,     0,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
       0,     0,     0,     0,   400,   401,   402,   403,     0,     0,
     920,     0,     0,     0,     0,     0,     0,     0,   400,   401,
     402,   403,     0,     0,   931,     0,     0,     0,     0,     0,
       0,     0,   400,   401,   402,   403,     0,     0,   979,     0,
       0,     0,     0,     0,     0,     0,   400,   401,   402,   403,
     391,   392,   980,     0,     0,     0,     0,   393,   394,   395,
     396,   397,   398,   399,   391,   392,     0,     0,     0,     0,
       0,   393,   394,   395,   396,   397,   398,   399,   391,     0,
       0,     0,     0,     0,     0,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,     0,     0,  1010,     0,
       0,     0,     0,     0,     0,     0,   400,   401,   402,   403,
       0,     0,  1059,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   400,   401,   402,   403,     0,     0,
    1077,     0,     0,     0,     0,     0,     0,     0,   400,   401,
     402,   403,     0,     0,  1110,     0,     0,     0,     0,     0,
       0,     0,   400,   401,   402,   403
};

static const yytype_int16 yycheck[] =
{
       2,    40,   200,    76,    47,    48,    15,    16,   309,    12,
     830,   831,    12,    58,    11,    17,     4,   275,   276,     7,
     218,     4,     4,     5,     7,     4,     5,    58,    30,    60,
      61,    33,    41,     4,    36,    37,    38,    75,    75,     0,
      42,    43,    44,    91,    92,     4,     3,   188,     7,    51,
       7,     8,     9,    10,   195,   103,   109,   193,     3,   195,
      25,    63,     7,     8,     9,    10,    16,     4,     5,    43,
      44,    20,    21,    70,    71,    72,    73,    74,    75,    44,
       4,     5,    12,    70,    71,    72,    73,    74,    75,    63,
      28,     7,   279,   280,    44,    33,    67,    99,    70,    71,
      72,    73,    74,    75,    94,   188,   188,    28,    23,    12,
     193,   193,   195,   195,    63,    64,   189,   190,    35,    36,
      99,    70,    71,    72,    73,    74,    75,    76,     4,     5,
     188,   188,     1,    63,    64,     4,   193,   195,   195,    87,
      70,    71,    72,    73,    74,    75,    76,     1,   188,    44,
       4,   196,   131,   132,   133,   195,   194,   194,   188,   188,
      63,    64,   194,   193,   193,   196,   195,    70,    71,    72,
      73,    74,    75,    76,   188,   188,   178,   179,   188,   193,
     193,   195,  1002,   193,    53,  1005,   194,   374,   188,   376,
     193,   188,   194,   193,   131,   132,   133,   199,    67,    53,
     194,   188,   241,   242,   188,   194,   194,   188,   195,   193,
     212,   194,   193,    67,   195,   217,   188,   475,   261,   188,
     188,   193,   224,   195,   267,   268,   195,   195,   188,    75,
     187,   188,   194,   491,   492,   195,   434,   188,   187,   188,
     189,   190,   187,   188,   195,   247,   188,   249,   291,   292,
     293,   193,   193,   195,   195,   188,   514,   187,   188,   189,
     190,   188,   195,   193,     4,     5,   193,   310,   195,    70,
      71,    72,    73,    74,    75,  1095,   188,     4,     5,   281,
     195,   193,   197,   195,   187,   188,   189,   190,   188,   188,
     192,   193,   294,   193,    13,   195,   195,   299,   300,   188,
     302,   303,   304,   305,   306,   307,   195,     4,     5,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
      75,   200,   306,   307,    24,   337,   338,   339,   340,   341,
     193,   343,   195,   345,    63,    64,   200,    76,   322,   218,
     194,    70,    71,    72,    73,    74,    75,    76,   360,   188,
     188,    85,    86,   365,   218,   188,   195,   195,    63,    64,
     194,   193,   195,   195,   194,    70,    71,    72,    73,    74,
      75,    76,   297,   298,   188,    46,   360,   188,   193,   193,
     195,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,    63,    64,    73,    74,    75,    76,   194,    70,
      71,    72,    73,    74,    75,    76,     5,   194,   616,   458,
     194,    10,    70,    71,    72,    73,    74,    75,   471,   188,
     188,   474,   188,   435,   193,   188,    59,   195,   440,   195,
     193,    71,    31,    73,    74,    75,    76,   362,   363,   451,
     452,    70,    71,    72,    73,    74,    75,   194,   187,   188,
     189,   190,   464,   194,   466,    88,    89,    90,   187,   188,
     189,   190,    95,   194,   476,   477,     4,     5,    44,    74,
      75,    76,   188,   485,   486,   487,   488,   194,   789,   195,
     194,   792,   187,   188,   189,   190,   188,    63,    64,   188,
     195,    49,    50,   195,    70,    71,    72,    73,    74,    75,
      76,     4,     5,    75,    76,   104,   188,   106,   187,   188,
     189,   190,    44,   195,   188,   188,   187,   188,   189,   190,
     188,   195,   195,   448,   449,   194,   188,   195,   453,   454,
     188,   193,   131,   132,   133,   194,   188,   195,   137,   138,
     139,   194,   141,   195,   143,   144,   145,   187,   188,   189,
     190,   150,   151,   152,   188,   434,   155,   194,   157,   188,
     159,   195,   188,   162,   193,   164,   188,   194,   167,   195,
     434,   170,   171,   195,   173,   174,   188,   176,   194,   178,
     194,   193,   187,   188,   189,   190,   194,   186,   600,   601,
     188,   188,   194,   861,   194,   194,   195,   195,   195,    14,
     194,    16,   194,    18,   194,   624,   625,   619,   816,   877,
     489,   187,   188,   189,   190,   187,   188,   189,   190,    14,
     632,    16,    58,    18,   188,   489,    41,   680,    14,    44,
      16,   195,    18,   645,    49,   188,    39,    40,   194,   651,
     652,   188,   195,   655,   697,   698,    41,     4,   195,    44,
     194,   188,    46,   188,    49,    41,   193,   669,    44,   188,
     195,   194,   188,    49,   188,   193,   195,   193,   721,    63,
      64,   195,   684,   685,   686,   194,    70,    71,    72,    73,
      74,    75,    76,   194,   696,    70,    71,    72,    73,    74,
      75,    76,   704,   705,   194,   707,   708,   709,   188,   188,
     194,   626,   627,   193,   629,   630,   195,   719,   720,   188,
     722,     4,     5,    14,   193,    16,   728,    18,   194,   731,
      71,    72,    73,    74,    75,    76,   194,   188,   188,     3,
     194,   743,   193,   193,   746,   747,   748,   616,   750,   751,
      41,    60,    61,    44,   188,   194,   758,    21,    49,   193,
      24,     3,   616,   194,   194,     7,     8,     9,   683,    33,
     188,   194,   194,    37,    38,   193,     5,   194,    42,   194,
     194,   194,   784,   194,   786,   787,   788,   194,   194,   193,
      54,    55,    56,   180,   181,   182,   183,   184,   800,    63,
      64,    65,    66,   187,   188,   189,   190,    51,   194,    43,
      76,   194,   187,   188,   189,   190,   194,   194,   820,    63,
      64,   194,   194,   194,   194,   194,    70,    71,    72,    73,
      74,    75,    76,   194,  1032,  1033,   194,   194,   194,   841,
     842,   194,   194,   194,   846,   847,   187,   188,   189,   190,
     852,   853,   194,    75,   194,   194,    63,    64,   194,   194,
     194,   194,   194,    70,    71,    72,    73,    74,    75,    76,
     194,   194,   846,   847,   194,  1073,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   193,  1084,   194,   194,  1087,
     194,   194,   194,   194,   194,   904,   905,   194,   193,   193,
     193,   193,  1100,   946,    43,   195,   195,   195,   910,   195,
     194,    46,   194,   915,   193,   179,   194,   194,   920,   193,
     193,    10,   194,   187,   839,   840,    63,    64,   195,   194,
      43,   194,   196,    70,    71,    72,    73,    74,    75,    76,
     942,   193,   193,   187,   188,   189,   190,   816,   212,   195,
     193,    84,   193,   217,   193,   195,   193,   195,   960,   194,
     224,   194,   816,   195,   966,   195,   193,   195,    84,   195,
     195,   973,   195,   975,   195,   195,   194,   194,   980,   195,
     187,   188,   189,   190,   248,   195,   193,   989,   195,   195,
     195,     5,   193,   193,   258,    58,   195,   999,   195,   195,
     195,   194,   194,   193,   195,   194,    43,   195,   195,   924,
     925,    38,    43,  1015,    63,    64,   194,    75,   282,   195,
     195,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      75,   295,  1034,    75,    58,    70,    71,    72,    73,    74,
      75,    76,   306,    48,   195,   195,   194,   194,    47,   194,
     187,   188,   189,   190,   194,    75,   193,  1059,   195,   195,
      38,   195,     4,    53,   489,    53,  1068,   458,   332,   333,
     334,   335,   336,   309,  1076,  1077,   632,     5,   342,   628,
     344,   631,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,  1056,   910,
     364,  1127,   366,   367,   368,   369,   370,   455,  1110,   373,
     828,   375,  1079,   377,   378,   379,    -1,    -1,   468,   383,
     384,   385,   386,   387,   388,   389,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,
     189,   190,    -1,    -1,   193,    -1,   195,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,   190,    -1,    -1,   193,    -1,
     195,    -1,    -1,  1032,  1033,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   437,    -1,    -1,    -1,    -1,  1032,  1033,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,   463,
      -1,    -1,    -1,    -1,  1073,    -1,    -1,    -1,   472,    -1,
      -1,    -1,    -1,    -1,    -1,  1084,    30,    31,  1087,  1073,
      -1,   485,   486,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1084,  1100,    -1,  1087,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1100,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    83,
      -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    -1,    -1,    -1,   100,   101,    -1,    -1,
     104,    -1,   106,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,    -1,   161,   162,   163,
     164,    -1,   166,   167,    -1,   169,   170,   171,    -1,   173,
     174,   175,   176,   177,   178,   179,    -1,    -1,   632,    -1,
      -1,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,    -1,
     194,    -1,   196,    -1,   648,    -1,    -1,   651,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
       5,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   711,    -1,   713,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   752,    -1,
      -1,     5,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   770,   771,    -1,   104,
      -1,   106,    -1,   777,    -1,    -1,    -1,    31,    -1,   187,
     188,   189,   190,    -1,    -1,   193,   790,   195,    -1,   793,
      -1,   795,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,
      -1,    -1,   137,   138,   139,    -1,   141,    -1,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,   151,   152,   822,    -1,
     155,   825,   157,    -1,   159,    -1,    -1,   162,    -1,   164,
      -1,    -1,   167,    -1,    -1,   170,   171,    -1,   173,   174,
      -1,   176,    -1,   178,   848,   849,   850,    -1,    -1,    -1,
     104,   186,   106,    -1,   858,   859,    -1,    -1,    -1,   194,
     195,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,   131,   132,   133,
      -1,    -1,    -1,   137,   138,   139,    -1,   141,    -1,   143,
     144,   145,    -1,    -1,    -1,    -1,   150,   151,   152,    -1,
      -1,   155,    -1,   157,    -1,   159,   910,    -1,   162,    -1,
     164,    -1,    -1,   167,    -1,    -1,   170,   171,    -1,   173,
     174,    -1,   176,    -1,   178,    -1,    -1,   931,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    63,    64,    -1,    -1,    -1,
     194,   195,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,   955,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,   970,    70,    71,    72,
      73,    74,    75,    76,    -1,   979,    -1,    -1,   982,    -1,
      -1,   985,    -1,    -1,    -1,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,  1000,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1009,  1010,  1011,  1012,    -1,
    1014,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,  1075,    -1,    -1,    -1,    -1,  1080,    63,    64,    65,
      66,    67,    68,    69,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    80,    -1,    -1,    83,    -1,    -1,
      -1,    -1,    88,    -1,  1108,    -1,    -1,    -1,    -1,    -1,
      96,    -1,    -1,    -1,   100,   101,    -1,    -1,   104,    -1,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,    -1,   161,   162,   163,   164,    -1,
     166,   167,    -1,   169,   170,   171,    -1,   173,   174,   175,
     176,   177,   178,   179,    -1,    -1,    -1,    -1,    -1,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,    -1,   194,    -1,
     196,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    63,
      64,    83,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    -1,    96,    -1,    -1,    -1,   100,   101,
      -1,    -1,   104,    -1,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,    -1,   161,
     162,   163,   164,    -1,   166,   167,    -1,   169,   170,   171,
      -1,   173,   174,   175,   176,   177,   178,   179,    -1,    -1,
      -1,    -1,    -1,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,    -1,   194,    -1,   196,     3,     4,     5,    -1,     7,
       8,     9,    10,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    63,    64,    83,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,   100,   101,    -1,    -1,   104,    -1,   106,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    -1,   161,   162,   163,   164,    -1,   166,   167,
      -1,   169,   170,   171,    -1,   173,   174,   175,   176,   177,
     178,   179,    -1,    -1,    -1,    -1,    -1,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,     3,
       4,     5,    -1,     7,     8,     9,    10,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,     5,    83,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   100,   101,    -1,    -1,
     104,    -1,   106,    -1,    31,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,    -1,   161,   162,   163,
     164,    -1,   166,   167,    -1,   169,   170,   171,    -1,   173,
     174,   175,   176,   177,   178,   179,    -1,   104,    -1,   106,
      -1,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,    -1,
     194,   195,     3,     4,     5,    -1,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,
     137,   138,   139,    -1,   141,    -1,   143,   144,   145,    30,
      31,    -1,    -1,   150,   151,   152,    -1,    -1,   155,    -1,
     157,    -1,   159,    -1,    -1,   162,    -1,   164,    -1,    -1,
     167,    -1,    -1,   170,   171,    -1,   173,   174,    -1,   176,
      -1,   178,    63,    64,    65,    66,    67,    68,    69,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,   195,    80,
      -1,     5,    83,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
     101,    -1,    -1,   104,    -1,   106,    -1,    31,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,    -1,
     161,   162,   163,   164,    -1,   166,   167,    -1,   169,   170,
     171,    -1,   173,   174,   175,   176,   177,   178,   179,    -1,
     104,    -1,   106,    -1,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,    -1,   194,   195,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,   131,   132,   133,
      -1,    -1,    -1,   137,   138,   139,    -1,   141,    -1,   143,
     144,   145,    30,    31,    -1,    -1,   150,   151,   152,    -1,
      -1,   155,    -1,   157,    -1,   159,    -1,    -1,   162,    -1,
     164,    -1,    -1,   167,    -1,    -1,   170,   171,    -1,   173,
     174,    -1,   176,    -1,   178,    63,    64,    65,    66,    67,
      68,    69,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    80,    -1,     5,    83,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   100,   101,    -1,    -1,   104,    -1,   106,    -1,
      31,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    -1,   161,   162,   163,   164,    -1,   166,   167,
      -1,   169,   170,   171,    -1,   173,   174,   175,   176,   177,
     178,   179,    -1,   104,    -1,   106,    -1,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,    -1,   194,   195,     3,     4,
       5,    -1,     7,     8,     9,    10,    -1,    12,    -1,    -1,
     131,   132,   133,    -1,    -1,    -1,   137,   138,   139,    -1,
     141,    -1,   143,   144,   145,    30,    31,    -1,    -1,   150,
     151,   152,    -1,    -1,   155,    -1,   157,    -1,   159,    -1,
      -1,   162,    -1,   164,    -1,    -1,   167,    -1,    53,   170,
     171,    -1,   173,   174,    -1,   176,    -1,   178,    63,    64,
      65,    66,    67,    68,    69,   186,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    80,    63,    64,    83,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,   100,   101,    -1,    -1,   104,
      -1,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,    -1,   161,   162,   163,   164,
      -1,   166,   167,    -1,   169,   170,   171,    -1,   173,   174,
     175,   176,   177,   178,   179,    -1,    -1,    -1,    -1,    -1,
     185,   186,   187,    -1,    -1,    -1,     3,     4,     5,   194,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    80,    -1,    -1,    83,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   100,   101,    -1,    -1,   104,    -1,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    -1,   161,   162,   163,   164,    -1,   166,
     167,    -1,   169,   170,   171,    -1,   173,   174,   175,   176,
     177,   178,   179,    -1,    -1,    -1,    -1,    -1,   185,   186,
     187,    -1,    -1,    -1,     3,     4,     5,   194,     7,     8,
       9,    10,    -1,    12,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    80,    -1,    -1,    83,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   100,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,    -1,   161,   162,   163,   164,    -1,   166,   167,    -1,
     169,   170,   171,    -1,   173,   174,   175,   176,   177,   178,
     179,    -1,    -1,    -1,    -1,    -1,   185,   186,   187,    -1,
      -1,    -1,     3,     4,     5,   194,     7,     8,     9,    10,
      -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
       5,    -1,    83,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
     101,    -1,    -1,   104,    -1,   106,    31,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,    -1,
     161,   162,   163,   164,    -1,   166,   167,    -1,   169,   170,
     171,    96,   173,   174,   175,   176,   177,   178,   179,   104,
      -1,   106,    -1,     5,   185,   186,   187,    -1,    10,    -1,
      -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,    31,
      -1,    -1,   137,   138,   139,    -1,   141,    -1,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,   151,   152,    -1,    -1,
     155,    -1,   157,    -1,   159,    -1,    -1,   162,    -1,   164,
      -1,    -1,   167,    -1,    -1,   170,   171,    -1,   173,   174,
      -1,   176,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    63,    64,
      -1,    -1,   104,    -1,   106,    70,    71,    72,    73,    74,
      75,    76,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,   137,   138,   139,    -1,   141,
      -1,   143,   144,   145,    -1,    -1,    -1,    -1,   150,   151,
     152,    -1,    -1,   155,    -1,   157,    -1,   159,    -1,    -1,
     162,    -1,   164,    -1,    -1,   167,    -1,    -1,   170,   171,
      -1,   173,   174,    -1,   176,    -1,   178,    -1,     4,     5,
       6,    -1,    -1,    -1,   186,    11,    -1,    -1,    -1,    15,
      -1,    17,   194,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,
      -1,    -1,   187,   188,   189,   190,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    61,    62,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    80,    81,    82,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    91,    92,    93,    94,    95,
      -1,    97,    98,    99,    -1,    -1,   102,   103,    -1,   105,
      -1,   107,   108,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,   165,
      -1,    -1,   168,    -1,    -1,    -1,   172,     4,     5,     6,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    15,   185,
      17,    -1,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    61,    62,    -1,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      77,    78,    79,    80,    81,    82,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    93,    94,    95,    -1,
      97,    98,    99,    -1,    -1,   102,    -1,    -1,   105,    -1,
     107,   108,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,   165,    -1,
      -1,   168,    -1,    -1,    -1,   172,     4,     5,     6,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    15,   185,    17,
      -1,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    -1,    -1,    -1,    42,    43,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    61,    62,    -1,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    77,
      78,    79,    80,    81,    82,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,    -1,   102,    63,    64,   105,    -1,   107,
     108,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,   131,   132,   133,    63,    64,    -1,    -1,
     138,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,
      -1,    -1,   160,    -1,    -1,    -1,    -1,   165,    63,    64,
     168,    -1,    -1,    -1,   172,    70,    71,    72,    73,    74,
      75,    76,    63,    64,    -1,    -1,    -1,   185,    -1,    70,
      71,    72,    73,    74,    75,    76,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   188,   189,   190,    63,    64,    -1,    -1,   195,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,   187,   188,   189,   190,    63,    64,
      -1,    -1,   195,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,   190,    63,    64,    -1,    -1,
     195,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
     187,   188,   189,   190,    63,    64,    -1,    -1,   195,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,   190,    63,    64,    -1,    -1,
     195,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,   190,    63,    64,    -1,    -1,
     195,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,   187,   188,
     189,   190,    63,    64,    -1,    -1,   195,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,   190,    63,    64,    -1,    -1,
     195,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
     187,   188,   189,   190,    63,    64,    -1,    -1,   195,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,   187,   188,
     189,   190,    63,    64,    -1,    -1,   195,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
     187,   188,   189,   190,    63,    64,    -1,    -1,   195,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
     187,   188,   189,   190,    63,    64,    -1,    -1,   195,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,
      63,    64,    -1,    -1,   195,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
     187,   188,   189,   190,    63,    64,    -1,    -1,   195,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,   187,   188,
     189,   190,    63,    64,   193,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,   187,   188,
     189,   190,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,   190,    -1,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,
      63,    64,   193,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   188,   189,   190,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,
     189,   190,    63,    64,   193,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,   187,   188,   189,   190,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,
     189,   190,    63,    64,   193,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   188,   189,   190,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   188,   189,   190,    63,    64,
     193,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,   187,   188,   189,   190,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   188,   189,   190,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,
     189,   190,    63,    64,   193,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,   190,    -1,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,
      63,    64,   193,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,   187,   188,   189,   190,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   188,   189,   190,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   188,   189,   190,    63,    64,
     193,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,
     189,   190,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,   190,    -1,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,
      63,    64,   193,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,   187,   188,   189,   190,    -1,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,
     189,   190,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,   190
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   180,   181,   182,   183,   184,   198,     4,     5,     6,
      11,    15,    17,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    42,
      45,    52,    53,    54,    55,    56,    57,    61,    62,    77,
      78,    79,    80,    81,    82,    88,    89,    90,    93,    94,
      95,    97,    98,    99,   102,   105,   107,   108,   131,   132,
     133,   138,   156,   160,   165,   168,   172,   185,   199,   200,
     202,   203,   210,   211,   213,   214,   218,   230,   231,   236,
     242,   249,   257,   265,   268,   272,   275,   281,     3,     4,
       5,     7,     8,     9,    10,    30,    31,    63,    64,    65,
      66,    67,    68,    69,    80,    83,   100,   101,   104,   106,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     161,   162,   163,   164,   166,   167,   169,   170,   171,   173,
     174,   175,   176,   177,   178,   179,   185,   186,   187,   194,
     216,   217,   219,   225,   227,   230,   231,   194,   216,   202,
     230,   231,   236,     0,    75,   194,    75,   194,   250,   269,
     273,     4,     7,   228,   228,   228,    34,   219,   204,   205,
     216,   232,   233,   232,   216,    28,     7,   258,   266,   219,
      58,    60,    61,   196,   304,   208,   216,   219,     4,     5,
     229,   219,   216,   219,   216,   219,     4,     5,   292,   293,
      10,   187,   188,   226,   227,   294,   228,    88,    96,   196,
     216,   219,   305,    88,    96,   109,   305,   305,    87,   219,
     224,    12,    53,   224,   224,    59,    88,    89,    90,    95,
      94,   219,   211,   218,   216,   216,   216,   109,   194,   194,
     194,   194,   194,   216,   305,   216,   216,   216,   202,    44,
     201,    91,    92,   103,    75,    75,    24,   194,   194,   194,
     194,   219,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     219,   216,   219,    70,    71,    72,    73,    74,    75,   188,
      44,    63,    64,    70,    71,    72,    73,    74,    75,    76,
     187,   188,   189,   190,   216,    44,   219,   232,   216,   232,
       4,   219,   200,    35,    36,    20,    21,     4,     5,   243,
     244,     4,     5,   245,   246,   216,   219,   234,   235,   216,
     219,   260,   200,   276,   282,   194,    58,   194,     4,     7,
     194,   216,   219,   295,    58,   196,   297,   302,   194,   194,
     193,   193,   193,   194,   194,   193,   227,   227,   193,   219,
     216,   219,    11,   193,   193,   216,   193,   224,   209,    12,
     193,   212,   193,   224,    12,   224,   212,   212,     5,   215,
     215,   215,   195,   219,   216,   193,   193,   193,   193,    43,
     224,   224,   224,   219,   216,   237,   232,   232,   219,   219,
     219,   219,   219,   219,    96,   216,   305,   305,     4,     5,
     222,   223,   222,   223,   224,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   305,   219,   219,   219,
     219,   219,   219,   219,   219,   195,   219,   216,   216,   216,
     216,   216,   219,   219,   219,   195,   219,   219,   216,   219,
     216,   219,   216,   216,   195,   216,   195,   216,   195,   216,
     195,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   305,   216,   232,   232,   216,   219,   216,   216,   216,
     216,   216,   195,   195,   216,   215,   216,   215,   216,   216,
     216,   195,   195,   216,   216,   216,   216,   216,   216,   216,
     221,   220,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   195,   195,    75,   270,    14,    16,    18,
      41,    44,    49,   274,   206,   207,   194,   194,   193,   194,
     194,   193,   193,    43,   259,    14,    16,    18,    41,    44,
      49,   267,    46,   200,   219,   194,   216,   219,    51,   296,
     192,   193,   194,     4,     7,   194,    10,   303,   232,   232,
       4,     5,   219,   219,   232,   232,   293,    10,   226,   193,
      85,    86,    96,   216,   219,   219,   297,   224,   216,   224,
     212,   219,   219,   194,   193,   193,   193,   195,   195,   216,
     219,   216,   219,   219,   219,   203,   193,   212,   212,     4,
       5,   241,   195,   195,   193,   193,   195,   193,   193,   193,
     195,   193,   195,   193,   195,   194,   194,   195,   195,   193,
     193,   212,   193,   195,   195,   195,   195,   195,   193,   195,
     195,   193,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   193,   195,   195,   193,   193,   193,   195,
     193,   193,   193,   195,   195,   195,   195,   195,   193,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     193,   193,   195,   195,   195,   195,   195,   193,   195,   195,
     195,   195,   195,   195,   193,   195,   193,   193,   193,   193,
     193,   195,   193,   193,   195,   193,   195,   195,   219,   219,
     251,   200,   219,   228,   306,   228,   307,   232,   232,   244,
     232,   232,   246,   235,    43,   261,   277,    49,    50,   283,
     193,   219,   193,   195,   195,   194,   216,   216,   219,   219,
     298,   299,   219,     4,     5,   289,   291,   195,   195,   194,
     194,   193,   193,   195,   195,   219,    84,    84,   193,   193,
     193,   224,   193,   193,   232,   219,   219,   219,   193,   193,
     219,   224,   224,   238,   219,   219,   219,   219,   219,   216,
      96,   216,   195,   195,   219,   219,   224,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   216,   219,   216,   216,
     216,   219,   219,   219,   219,   223,   216,   223,   216,   216,
     219,    16,    44,   271,   193,   193,   195,   195,   195,   195,
      39,    40,   263,   200,   219,   193,   216,    58,   216,   296,
     193,   289,   289,   195,   194,   194,   193,   232,   232,   219,
     219,   193,   305,   305,   216,   216,   216,   219,   219,   195,
     195,   195,   193,   195,   216,   216,   212,   194,   195,   195,
     195,   195,   195,   195,   195,   193,   195,   195,   195,   195,
     212,   195,   195,   195,   195,   195,   193,   195,   195,   195,
     193,   195,   195,   193,   195,   193,   195,   195,   195,   193,
     193,   195,   193,   195,   195,   193,   195,   195,   195,    12,
     228,   228,   260,    43,    38,   278,   195,   219,   195,   194,
     193,   219,   300,   232,   232,   290,   195,   195,   216,   193,
     193,    75,    75,   219,    75,   193,   224,     4,     5,   247,
     248,   216,   219,   219,   216,   219,   219,   216,   219,   216,
     216,   219,   262,   264,    48,   285,    60,    61,   195,    58,
     219,   216,   195,   289,   195,   195,   289,   216,   216,   216,
     216,   195,   216,   219,   194,   194,   193,   195,   195,   193,
     195,   195,   195,   195,   195,   195,   195,   195,    13,   255,
     200,   200,   219,    47,   284,   194,   194,   193,   195,   301,
      75,   195,   195,   248,   239,   219,   219,   252,    46,   288,
     200,   279,   216,   219,   219,   303,   216,   200,   195,   200,
     286,    14,    16,    18,    41,    44,    49,   280,   193,   195,
     193,   195,   289,    25,    44,   240,   253,   200,   216,   219,
      14,    16,    18,    41,    44,    49,   254,   287,   195,   195,
       4,   256,   285
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   197,   198,   198,   198,   198,   198,   199,   200,   201,
     200,   202,   202,   202,   202,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     204,   203,   205,   203,   203,   203,   203,   203,   203,   203,
     206,   203,   207,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   208,   203,   209,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   210,   210,
     210,   210,   210,   211,   211,   211,   211,   211,   211,   212,
     212,   213,   213,   213,   213,   213,   214,   214,   215,   215,
     216,   216,   216,   216,   216,   216,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   218,   218,   220,   219,
     221,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   222,   223,   224,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   226,   226,   226,   227,
     227,   227,   227,   228,   228,   229,   229,   229,   229,   230,
     231,   233,   232,   234,   234,   234,   235,   235,   237,   238,
     239,   236,   240,   240,   241,   241,   242,   242,   242,   242,
     243,   243,   244,   244,   244,   244,   245,   245,   246,   246,
     246,   246,   247,   247,   247,   248,   248,   248,   248,   250,
     251,   252,   253,   249,   254,   254,   254,   254,   254,   254,
     255,   255,   256,   256,   258,   257,   259,   259,   260,   260,
     261,   262,   261,   263,   264,   263,   266,   265,   267,   267,
     267,   267,   267,   267,   269,   270,   268,   271,   271,   273,
     272,   274,   274,   274,   274,   274,   274,   276,   277,   278,
     279,   275,   280,   280,   280,   280,   280,   280,   282,   281,
     283,   283,   284,   284,   285,   286,   287,   285,   288,   288,
     289,   290,   289,   291,   291,   291,   291,   292,   292,   293,
     293,   293,   293,   294,   294,   294,   294,   295,   295,   295,
     295,   295,   296,   296,   296,   298,   297,   299,   297,   300,
     297,   301,   297,   302,   297,   303,   303,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   305,   305,   306,   306,   307,   307
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     2,     2,     3,     2,     1,     0,
       4,     1,     2,     1,     2,     0,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       0,     3,     0,     3,     1,     1,     2,     2,     3,     3,
       0,     5,     0,     5,     2,     1,     2,     1,     2,     2,
       2,     2,     3,     4,     4,     0,     3,     0,     4,     6,
       2,     6,     2,     2,     2,     1,     2,     1,     2,     2,
       2,     5,     7,     3,     2,     3,     4,     5,     3,     2,
       4,     3,     8,     6,     6,     2,     2,     5,     7,     4,
       6,     8,     5,     2,     2,     2,     2,     3,     2,     2,
       1,     1,     3,     4,     4,     4,     4,     4,     4,     1,
       1,     2,     1,     2,     2,     8,     6,     6,     0,     1,
       1,     2,     2,     3,    10,     8,     8,     8,     3,     1,
       1,     6,     4,     4,     6,     6,     4,     6,     1,     4,
       1,     1,     1,     1,     3,     3,     6,     6,     8,     6,
       4,     6,     8,     1,     3,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     1,     3,
       1,     3,     4,     6,     6,     4,     6,     4,     6,    10,
       4,     4,     4,     8,     6,     4,     3,     3,     0,     4,
       0,     4,     2,     3,     3,     3,     3,     3,     3,     4,
       6,     1,     4,     4,     6,     6,     1,     1,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     4,     4,     4,     4,     4,
       4,     6,     4,     4,     6,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     3,     6,     6,     4,
       4,     4,     4,     6,     6,     8,     6,     8,     4,     4,
       4,     8,     4,     4,     4,     4,     1,     3,     4,     1,
       3,     4,     1,     3,     4,     1,     3,     6,     6,     4,
       6,     6,     6,     4,     8,     6,     8,     6,     4,     4,
       4,     6,     6,     6,     8,     4,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     4,     6,     4,     6,     4,
       4,     0,     2,     0,     1,     3,     1,     1,     0,     0,
       0,    11,     1,     1,     1,     1,     0,     1,     1,     2,
       1,     3,     1,     1,     4,     4,     1,     3,     1,     1,
       4,     4,     0,     1,     3,     1,     1,     3,     3,     0,
       0,     0,     0,    14,     1,     1,     1,     1,     1,     1,
       0,     2,     0,     1,     0,     7,     1,     2,     1,     1,
       0,     0,     5,     0,     0,     4,     0,     4,     1,     1,
       1,     1,     1,     1,     0,     0,     6,     1,     1,     0,
       4,     1,     2,     1,     1,     1,     1,     0,     0,     0,
       0,    11,     1,     1,     1,     1,     1,     1,     0,     5,
       1,     1,     0,     2,     0,     0,     0,     7,     0,     1,
       1,     0,     4,     1,     4,     1,     4,     1,     3,     1,
       4,     1,     4,     1,     1,     3,     3,     0,     2,     4,
       1,     3,     0,     2,     6,     0,     4,     0,     4,     0,
       6,     0,     9,     0,     3,     0,     1,     0,     2,     2,
       4,     1,     4,     6,     6,     7,    10,    12,     7,    10,
      12,     2,     1,     1,     3,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

    {YYACCEPT;}

    break;

  case 6:

    {YYACCEPT;}

    break;

  case 7:

    {YYACCEPT;}

    break;

  case 9:

    {if (severity_so_far >= sERROR) {YYABORT;}}

    break;

  case 17:

    {report_if_missing("can not import a library in a loop or an if-statement",FALSE);}

    break;

  case 18:

    {add_command(cERROR);}

    break;

  case 24:

    {add_command(cPOP_MULTI);create_mybreak(1);if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}

    break;

  case 25:

    {add_command(cPOP_MULTI);create_mybreak(atoi((yyvsp[0].digits)));if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}

    break;

  case 26:

    {add_command(cPOP_MULTI);add_command_with_switch_state(cCONTINUE);if (!loop_nesting) lyyerror(sERROR,"continue outside loop");}

    break;

  case 28:

    {create_call((yyvsp[0].symbol));add_command(cPOP);}

    break;

  case 29:

    {create_call((yyvsp[0].symbol));add_command(cPOP);}

    break;

  case 30:

    {if (function_type==ftNONE) lyyerror(sERROR,"no use for 'local' outside functions");}

    break;

  case 32:

    {if (function_type==ftNONE) lyyerror(sERROR,"no use for 'static' outside functions");}

    break;

  case 36:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}

    break;

  case 37:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}

    break;

  case 38:

    {create_exception(TRUE);}

    break;

  case 39:

    {create_exception(FALSE);}

    break;

  case 40:

    {add_command(cSKIPPER);}

    break;

  case 41:

    {add_command(cNOP);}

    break;

  case 42:

    {add_command(cSKIPPER);}

    break;

  case 43:

    {add_command(cNOP);}

    break;

  case 44:

    {create_label((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol),cLABEL);}

    break;

  case 45:

    {add_command(cCHECKOPEN);}

    break;

  case 46:

    {add_command(cCLOSE);}

    break;

  case 47:

    {add_command(cCHECKSEEK);}

    break;

  case 48:

    {add_command(cCOMPILE);}

    break;

  case 49:

    {create_execute(0);add_command(cPOP);add_command(cPOP);}

    break;

  case 50:

    {create_execute(1);add_command(cPOP);add_command(cPOP);}

    break;

  case 51:

    {create_eval(evASSIGNMENT);}

    break;

  case 52:

    {create_colour(0);create_print('n');create_pps(cPOPSTREAM,0);}

    break;

  case 53:

    {create_colour(0);create_pps(cPOPSTREAM,0);}

    break;

  case 54:

    {create_colour(0);create_print('t');create_pps(cPOPSTREAM,0);}

    break;

  case 55:

    {tileol=FALSE;}

    break;

  case 57:

    {tileol=TRUE;}

    break;

  case 59:

    {add_command(cGCOLOUR);}

    break;

  case 60:

    {add_command(cGCOLOUR2);}

    break;

  case 61:

    {add_command(cGBACKCOLOUR);}

    break;

  case 62:

    {add_command(cGBACKCOLOUR2);}

    break;

  case 65:

    {create_restore("");}

    break;

  case 66:

    {create_restore((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}

    break;

  case 67:

    {if (function_type!=ftNONE) {
	       add_command(cCLEARSYMREFS);end_symref_chain();
	       add_command(cPOPSYMLIST);
               create_check_return_value(ftNONE,function_type);
               add_command(cRETURN_FROM_CALL);
             } else {
               add_command(cRETURN_FROM_GOSUB);
            }}

    break;

  case 68:

    {if (function_type==ftNONE) {lyyerror(sERROR,"a value can only be returned from a subroutine"); YYABORT;} add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNUMBER,function_type);add_command(cRETURN_FROM_CALL);}

    break;

  case 69:

    {if (function_type==ftNONE) {lyyerror(sERROR,"can not return value"); YYABORT;} add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftSTRING,function_type);add_command(cRETURN_FROM_CALL);}

    break;

  case 71:

    {create_openwin(FALSE);}

    break;

  case 72:

    {create_openwin(TRUE);}

    break;

  case 73:

    {add_command(cMOVEORIGIN);}

    break;

  case 74:

    {add_command(cDOT);}

    break;

  case 75:

    {add_command(cDOT);putindrawmode(dmCLEAR);}

    break;

  case 76:

    {create_line(2);}

    break;

  case 77:

    {create_line(2);putindrawmode(dmCLEAR);}

    break;

  case 78:

    {create_line(1);}

    break;

  case 79:

    {create_line(1);}

    break;

  case 80:

    {create_line(1);putindrawmode(dmCLEAR);}

    break;

  case 81:

    {create_line(1);putindrawmode(dmCLEAR);}

    break;

  case 82:

    {add_command(cPUTBIT);}

    break;

  case 83:

    {create_pushstr("solid"); add_command(cPUTBIT);}

    break;

  case 84:

    {add_command(cPUTCHAR);}

    break;

  case 85:

    {create_line(-1);}

    break;

  case 86:

    {create_line(0);}

    break;

  case 87:

    {add_command(cCIRCLE);putindrawmode(0);}

    break;

  case 88:

    {add_command(cTRIANGLE);putindrawmode(0);}

    break;

  case 89:

    {add_command(cTEXT1);}

    break;

  case 90:

    {add_command(cTEXT2);}

    break;

  case 91:

    {add_command(cTEXT3);}

    break;

  case 92:

    {add_command(cRECT);putindrawmode(0);}

    break;

  case 93:

    {add_command(cCLOSEWIN);}

    break;

  case 94:

    {add_command(cCLEARWIN);}

    break;

  case 95:

    {add_command(cCLEARSCR);}

    break;

  case 96:

    {create_openprinter(0);}

    break;

  case 97:

    {create_openprinter(1);}

    break;

  case 98:

    {add_command(cCLOSEPRN);}

    break;

  case 99:

    {add_command(cWAIT);}

    break;

  case 100:

    {add_command(cBELL);}

    break;

  case 101:

    {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}

    break;

  case 102:

    {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}

    break;

  case 103:

    {create_function(fINKEY);add_command(cPOP);}

    break;

  case 104:

    {create_function(fSYSTEM);
	add_command(cPOP);}

    break;

  case 105:

    {create_poke('s');}

    break;

  case 106:

    {create_poke('d');}

    break;

  case 107:

    {create_poke('S');}

    break;

  case 108:

    {create_poke('D');}

    break;

  case 109:

    {add_command(cEND);}

    break;

  case 110:

    {create_pushdbl(0);add_command(cEXIT);}

    break;

  case 111:

    {add_command(cEXIT);}

    break;

  case 112:

    {create_docu((yyvsp[0].symbol));}

    break;

  case 113:

    {add_command(cBIND);}

    break;

  case 114:

    {add_command(cFRNBF_FREE);}

    break;

  case 115:

    {add_command(cFRNBF_SET_NUMBER);}

    break;

  case 116:

    {add_command(cFRNBF_SET_STRING);}

    break;

  case 117:

    {add_command(cFRNBF_SET_BUFFER);}

    break;

  case 118:

    {drawmode=0;}

    break;

  case 119:

    {drawmode=dmCLEAR;}

    break;

  case 120:

    {drawmode=dmFILL;}

    break;

  case 121:

    {drawmode=dmFILL+dmCLEAR;}

    break;

  case 122:

    {drawmode=dmFILL+dmCLEAR;}

    break;

  case 123:

    {add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}

    break;

  case 124:

    {create_changestring(fMID);}

    break;

  case 125:

    {create_changestring(fMID2);}

    break;

  case 126:

    {create_changestring(fLEFT);}

    break;

  case 127:

    {create_changestring(fRIGHT);}

    break;

  case 128:

    {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 131:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 132:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 133:

    {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}

    break;

  case 134:

    {add_command(cSWAP);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 135:

    {add_command(cSWAP);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 136:

    {add_command(cSEEK);}

    break;

  case 137:

    {add_command(cSEEK2);}

    break;

  case 138:

    {add_command_with_sym_and_diag(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 139:

    {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}

    break;

  case 140:

    {add_command_with_sym_and_diag(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 142:

    {add_command_with_sym_and_diag(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}

    break;

  case 143:

    {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}

    break;

  case 144:

    {add_command(cCONCAT);}

    break;

  case 146:

    {create_function(fLEFT);}

    break;

  case 147:

    {create_function(fRIGHT);}

    break;

  case 148:

    {create_function(fMID);}

    break;

  case 149:

    {create_function(fMID2);}

    break;

  case 150:

    {create_function(fSTR);}

    break;

  case 151:

    {create_function(fSTR2);}

    break;

  case 152:

    {create_function(fSTR3);}

    break;

  case 153:

    {create_pushdbl(-1);create_function(fINKEY);}

    break;

  case 154:

    {create_pushdbl(-1);create_function(fINKEY);}

    break;

  case 155:

    {create_function(fINKEY);}

    break;

  case 156:

    {create_function(fCHR);}

    break;

  case 157:

    {create_function(fUPPER);}

    break;

  case 158:

    {create_function(fLOWER);}

    break;

  case 159:

    {create_function(fLTRIM);}

    break;

  case 160:

    {create_function(fRTRIM);}

    break;

  case 161:

    {create_function(fTRIM);}

    break;

  case 162:

    {create_function(fCHOMP);}

    break;

  case 163:

    {create_function(fSYSTEM2);}

    break;

  case 164:

    {create_function(fFRNFN_CALL2);}

    break;

  case 165:

    {create_function(fFRNBF_ALLOC);}

    break;

  case 166:

    {create_function(fFRNBF_DUMP);}

    break;

  case 167:

    {create_function(fFRNBF_DUMP2);}

    break;

  case 168:

    {create_function(fDATE);}

    break;

  case 169:

    {create_function(fDATE);}

    break;

  case 170:

    {create_function(fTIME);}

    break;

  case 171:

    {create_function(fTIME);}

    break;

  case 172:

    {create_function(fPEEK2);}

    break;

  case 173:

    {create_function(fPEEK3);}

    break;

  case 174:

    {add_command(cTOKENALT2);}

    break;

  case 175:

    {add_command(cTOKENALT);}

    break;

  case 176:

    {add_command(cSPLITALT2);}

    break;

  case 177:

    {add_command(cSPLITALT);}

    break;

  case 178:

    {create_function(fGETBIT);}

    break;

  case 179:

    {create_function(fGETCHAR);}

    break;

  case 180:

    {create_function(fHEX);}

    break;

  case 181:

    {create_function(fBIN);}

    break;

  case 182:

    {create_execute(1);add_command(cSWAP);add_command(cPOP);}

    break;

  case 183:

    {create_function(fFRNBF_GET_STRING);}

    break;

  case 184:

    {create_function(fFRNBF_GET_BUFFER);}

    break;

  case 185:

    {create_eval(evSTRING);}

    break;

  case 186:

    {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}

    break;

  case 187:

    {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}

    break;

  case 188:

    {add_command(cORSHORT);pushlabel();}

    break;

  case 189:

    {poplabel();create_boole('|');}

    break;

  case 190:

    {add_command(cANDSHORT);pushlabel();}

    break;

  case 191:

    {poplabel();create_boole('&');}

    break;

  case 192:

    {create_boole('!');}

    break;

  case 193:

    {create_dblrelop('=');}

    break;

  case 194:

    {create_dblrelop('!');}

    break;

  case 195:

    {create_dblrelop('<');}

    break;

  case 196:

    {create_dblrelop('{');}

    break;

  case 197:

    {create_dblrelop('>');}

    break;

  case 198:

    {create_dblrelop('}');}

    break;

  case 199:

    {add_command(cTESTEOF);}

    break;

  case 200:

    {add_command(cGLOB);}

    break;

  case 201:

    {create_pushdbl((yyvsp[0].fnum));}

    break;

  case 202:

    {add_command_with_sym_and_diag(cARDIM,"",NULL);}

    break;

  case 203:

    {add_command_with_sym_and_diag(cARDIM,"",NULL);}

    break;

  case 204:

    {add_command_with_sym_and_diag(cARSIZE,"",NULL);}

    break;

  case 205:

    {add_command_with_sym_and_diag(cARSIZE,"",NULL);}

    break;

  case 206:

    {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}

    break;

  case 207:

    {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 208:

    {create_dblbin('+');}

    break;

  case 209:

    {create_dblbin('-');}

    break;

  case 210:

    {create_dblbin('*');}

    break;

  case 211:

    {create_dblbin('/');}

    break;

  case 212:

    {create_dblbin('^');}

    break;

  case 213:

    {add_command(cNEGATE);}

    break;

  case 214:

    {create_strrelop('=');}

    break;

  case 215:

    {create_strrelop('!');}

    break;

  case 216:

    {create_strrelop('<');}

    break;

  case 217:

    {create_strrelop('{');}

    break;

  case 218:

    {create_strrelop('>');}

    break;

  case 219:

    {create_strrelop('}');}

    break;

  case 222:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 223:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 225:

    {create_function(fSIN);}

    break;

  case 226:

    {create_function(fASIN);}

    break;

  case 227:

    {create_function(fCOS);}

    break;

  case 228:

    {create_function(fACOS);}

    break;

  case 229:

    {create_function(fTAN);}

    break;

  case 230:

    {create_function(fATAN);}

    break;

  case 231:

    {create_function(fATAN2);}

    break;

  case 232:

    {create_function(fEXP);}

    break;

  case 233:

    {create_function(fLOG);}

    break;

  case 234:

    {create_function(fLOG2);}

    break;

  case 235:

    {create_function(fSQRT);}

    break;

  case 236:

    {create_function(fSQR);}

    break;

  case 237:

    {create_function(fINT);}

    break;

  case 238:

    {create_function(fROUND);}

    break;

  case 239:

    {create_function(fCEIL);}

    break;

  case 240:

    {create_function(fFLOOR);}

    break;

  case 241:

    {create_function(fFRAC);}

    break;

  case 242:

    {create_function(fABS);}

    break;

  case 243:

    {create_function(fSIG);}

    break;

  case 244:

    {create_function(fMOD);}

    break;

  case 245:

    {create_function(fRAN);}

    break;

  case 246:

    {create_function(fRAN2);}

    break;

  case 247:

    {create_function(fMIN);}

    break;

  case 248:

    {create_function(fMAX);}

    break;

  case 249:

    {create_function(fLEN);}

    break;

  case 250:

    {create_function(fVAL);}

    break;

  case 251:

    {create_function(fASC);}

    break;

  case 252:

    {create_function(fDEC);}

    break;

  case 253:

    {create_function(fDEC2);}

    break;

  case 254:

    {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}

    break;

  case 255:

    {create_function(fINSTR2);}

    break;

  case 256:

    {create_function(fRINSTR);}

    break;

  case 257:

    {create_function(fRINSTR2);}

    break;

  case 258:

    {create_function(fSYSTEM);}

    break;

  case 259:

    {create_function(fFRNFN_CALL);}

    break;

  case 260:

    {create_function(fFRNFN_SIZE);}

    break;

  case 261:

    {create_function(fFRNBF_GET_NUMBER);}

    break;

  case 262:

    {create_function(fFRNBF_SIZE);}

    break;

  case 263:

    {create_function(fPEEK4);}

    break;

  case 264:

    {create_function(fPEEK);}

    break;

  case 265:

    {create_function(fMOUSEX);}

    break;

  case 266:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 267:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 268:

    {create_function(fMOUSEY);}

    break;

  case 269:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 270:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 271:

    {create_function(fMOUSEB);}

    break;

  case 272:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 273:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 274:

    {create_function(fMOUSEMOD);}

    break;

  case 275:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 276:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 277:

    {create_function(fAND);}

    break;

  case 278:

    {create_function(fOR);}

    break;

  case 279:

    {create_function(fBITNOT);}

    break;

  case 280:

    {create_function(fEOR);}

    break;

  case 281:

    {create_function(fSHL);}

    break;

  case 282:

    {create_function(fSHR);}

    break;

  case 283:

    {create_function(fTELL);}

    break;

  case 284:

    {add_command(cTOKEN2);}

    break;

  case 285:

    {add_command(cTOKEN);}

    break;

  case 286:

    {add_command(cSPLIT2);}

    break;

  case 287:

    {add_command(cSPLIT);}

    break;

  case 288:

    {create_execute(0);add_command(cSWAP);add_command(cPOP);}

    break;

  case 289:

    {create_myopen(OPEN_PRINTER);}

    break;

  case 290:

    {create_myopen(0);}

    break;

  case 291:

    {create_myopen(OPEN_HAS_MODE);}

    break;

  case 292:

    {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}

    break;

  case 293:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 294:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 295:

    {create_eval(evNUMBER);}

    break;

  case 296:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 297:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 298:

    {(yyval.fnum)=-(yyvsp[0].fnum);}

    break;

  case 299:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 300:

    {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}

    break;

  case 301:

    {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}

    break;

  case 302:

    {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}

    break;

  case 303:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}

    break;

  case 304:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 305:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 306:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 307:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 308:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 309:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 310:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 311:

    {add_command(cPUSHFREE);}

    break;

  case 318:

    {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}

    break;

  case 319:

    {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}

    break;

  case 320:

    {create_require(stFREE);add_command(cPOP);}

    break;

  case 321:

    {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}

    break;

  case 322:

    {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 323:

    {missing_endsub--;}

    break;

  case 324:

    {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 325:

    {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 326:

    {exported=FALSE;}

    break;

  case 327:

    {exported=TRUE;}

    break;

  case 328:

    {exported=FALSE;}

    break;

  case 329:

    {exported=TRUE;}

    break;

  case 332:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}

    break;

  case 333:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}

    break;

  case 334:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}

    break;

  case 335:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}

    break;

  case 338:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}

    break;

  case 339:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}

    break;

  case 340:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}

    break;

  case 341:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}

    break;

  case 345:

    {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 346:

    {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 347:

    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 348:

    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 349:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}

    break;

  case 350:

    {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}

    break;

  case 351:

    { /* pushes another expression */
	     add_command(cSKIPONCE);
	     pushlabel();
	     add_command(cSTARTFOR);
	     add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     poplabel();

	     add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command(cSKIPONCE);
	     add_command(cFORINCREMENT);
	     add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command(cFORCHECK);
	     add_command(cDECIDE);
             pushlabel();}

    break;

  case 352:

    {
             swap();popgoto();poplabel();}

    break;

  case 353:

    {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}

    break;

  case 354:

    {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 355:

    {missing_next--;}

    break;

  case 356:

    {report_conflicting_close("a closing next is expected before endif",'e');}

    break;

  case 357:

    {report_conflicting_close("a closing next is expected before wend",'w');}

    break;

  case 358:

    {report_conflicting_close("a closing next is expected before until",'l');}

    break;

  case 359:

    {report_conflicting_close("a closing next is expected before loop",'l');}

    break;

  case 360:

    {create_pushdbl(1);}

    break;

  case 362:

    {pop(stSTRING);}

    break;

  case 363:

    {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }

    break;

  case 364:

    {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}

    break;

  case 365:

    {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}

    break;

  case 371:

    {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}

    break;

  case 372:

    {add_command(cNEXT_CASE_HERE);}

    break;

  case 374:

    {add_command(cNEXT_CASE_HERE);}

    break;

  case 376:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}

    break;

  case 378:

    {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 379:

    {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}

    break;

  case 380:

    {report_conflicting_close("a closing loop is expected before endif",'e');}

    break;

  case 381:

    {report_conflicting_close("a closing loop is expected before wend",'w');}

    break;

  case 382:

    {report_conflicting_close("a closing loop is expected before until",'l');}

    break;

  case 383:

    {report_conflicting_close("a closing loop is expected before next",'n');}

    break;

  case 384:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}

    break;

  case 385:

    {add_command(cDECIDE);
	      pushlabel();}

    break;

  case 387:

    {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 388:

    {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}

    break;

  case 389:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}

    break;

  case 391:

    {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 392:

    {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}

    break;

  case 393:

    {report_conflicting_close("a closing until is expected before endif",'e');}

    break;

  case 394:

    {report_conflicting_close("a closing until is expected before wend",'w');}

    break;

  case 395:

    {report_conflicting_close("a closing until is expected before loop",'l');}

    break;

  case 396:

    {report_conflicting_close("a closing until is expected before next",'n');}

    break;

  case 397:

    {add_command(cDECIDE);storelabel();pushlabel();}

    break;

  case 398:

    {missing_endif++;missing_endif_line=yylineno;}

    break;

  case 399:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 400:

    {poplabel();}

    break;

  case 402:

    {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'fi' at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 403:

    {missing_endif--;}

    break;

  case 404:

    {report_conflicting_close("a closing endif is expected before wend",'w');}

    break;

  case 405:

    {report_conflicting_close("a closing endif is expected before until",'l');}

    break;

  case 406:

    {report_conflicting_close("a closing endif is expected before loop",'l');}

    break;

  case 407:

    {report_conflicting_close("a closing endif is expected before next",'n');}

    break;

  case 408:

    {in_short_if++;add_command(cDECIDE);pushlabel();}

    break;

  case 410:

    {error(sERROR,"an if-statement without 'then' does not allow 'endif'");}

    break;

  case 411:

    {poplabel();}

    break;

  case 415:

    {add_command(cDECIDE);pushlabel();}

    break;

  case 416:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 421:

    {add_command(cCHKPROMPT);}

    break;

  case 423:

    {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 424:

    {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 425:

    {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 426:

    {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 429:

    {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 430:

    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 431:

    {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 432:

    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 433:

    {create_strdata((yyvsp[0].string));}

    break;

  case 434:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 435:

    {create_strdata((yyvsp[0].string));}

    break;

  case 436:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 440:

    {create_print('s');}

    break;

  case 441:

    {create_print('s');}

    break;

  case 442:

    {create_print('d');}

    break;

  case 443:

    {create_print('u');}

    break;

  case 444:

    {create_print('U');}

    break;

  case 445:

    {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}

    break;

  case 446:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 447:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}

    break;

  case 448:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 449:

    {create_pps(cPUSHSTREAM,1);}

    break;

  case 450:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 451:

    {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 452:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 453:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 454:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 455:

    {create_pushstr("?");create_print('s');}

    break;

  case 456:

    {create_pushstr((yyvsp[0].string));create_print('s');}

    break;

  case 457:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 458:

    {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}

    break;

  case 459:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}

    break;

  case 460:

    {create_pps(cPUSHSTREAM,0);}

    break;

  case 461:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 462:

    {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 463:

    {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 464:

    {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 465:

    {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 466:

    {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 467:

    {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 468:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}

    break;

  case 469:

    {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 470:

    {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 473:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}

    break;

  case 474:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}

    break;

  case 475:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}

    break;

  case 476:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}

    break;



      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
