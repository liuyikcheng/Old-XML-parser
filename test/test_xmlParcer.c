#include "unity.h"
#include <stdlib.h>
#include "xmlParcer.h"
#include "mock_Token.h"
#include "CException.h"
#include "ErrorObject.h"
#include "TokenCreate.h"
#include "stdio.h"
#include "linkedlist.h"

void setUp(void){}

void tearDown(void){}


/**
 *
 *                                                    
 *		<name>ABC DEF</name>        
 *                                       
 */
void test_moking_getToken(void){
	ErrorObject* err;
  Tag tag;
	XmlList *xmlList = malloc(sizeof(XmlList));
	
	xmlList = createXmlList();
	
	
	Token *leftAngleBracket   = (Token*)createOperatorToken("<");
	Token *rightAngleBracket  = (Token*)createOperatorToken(">");
	Token *slash              = (Token*)createOperatorToken("/");
  Token *idName             = (Token*)createIdentifierToken("name");
  Token *contentName        = (Token*)createStringToken("ABC");
  Token *contentName1       = (Token*)createStringToken("DEF");
  
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idName);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(contentName);	
	getToken_ExpectAndReturn(contentName1);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idName);	
	getToken_ExpectAndReturn(rightAngleBracket);	

  xmlList = checkToken();
  TEST_ASSERT_NOT_EQUAL(xmlList->head, NULL);
  TEST_ASSERT_NOT_EQUAL(xmlList->tail, NULL);

}

/**
 *
 * given:
 *  <data>
 *		<name></name>
 *  </data>
 *
 *
 */
 
void test_display(void){
  CEXCEPTION_T err;
  Tag tag;
	Token *leftAngleBracket   = (Token*)createOperatorToken("<");
	Token *rightAngleBracket  = (Token*)createOperatorToken(">");
	Token *slash              = (Token*)createOperatorToken("/");
  Token *idName             = (Token*)createIdentifierToken("name");
  Token *idData             = (Token*)createIdentifierToken("data");
  Token *contentName        = (Token*)createStringToken("ABC");
  
	XmlList *xmlList = malloc(sizeof(XmlList));
	
	xmlList = createXmlList();
	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idData);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idName);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idName);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idData);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	
  checkToken(xmlList);
}

/**
 *
 * given:
 *  <data>
 *		<name>ABC</name>
 *  </data>
 *
 *
 */

void xtest_display1(void){
  CEXCEPTION_T err;
  Tag tag;
	Token *leftAngleBracket   = (Token*)createOperatorToken("<");
	Token *rightAngleBracket  = (Token*)createOperatorToken(">");
	Token *slash              = (Token*)createOperatorToken("/");
  Token *idName             = (Token*)createIdentifierToken("name");
  Token *idData             = (Token*)createIdentifierToken("data");
  Token *contentName        = (Token*)createStringToken("ABC");
  
	XmlList *xmlList = malloc(sizeof(XmlList));
	
	xmlList = createXmlList();
	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idData);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idName);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(contentName);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idName);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idData);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	
  checkToken(xmlList);
}

/**
 *
 * given:
 *  <data>
 *		<name>ABC</name>
 *    <age>18</age>
 *  </data>
 *
 *
 */

void test_display2(void){
  CEXCEPTION_T err;
  Tag tag;
	Token *leftAngleBracket   = (Token*)createOperatorToken("<");
	Token *rightAngleBracket  = (Token*)createOperatorToken(">");
	Token *slash              = (Token*)createOperatorToken("/");
  Token *idName             = (Token*)createIdentifierToken("name");
  Token *idAge              = (Token*)createIdentifierToken("age");
  Token *idData             = (Token*)createIdentifierToken("data");
  Token *contentName        = (Token*)createStringToken("ABC");
  Token *contentAge         = (Token*)createStringToken("18");
  
	XmlList *xmlList = malloc(sizeof(XmlList));
	
	xmlList = createXmlList();
	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idData);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idName);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(contentName);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idName);	
	getToken_ExpectAndReturn(rightAngleBracket);	
  getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idAge);	
  getToken_ExpectAndReturn(rightAngleBracket);
  getToken_ExpectAndReturn(contentAge);
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idAge);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idData);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	Try{
  checkToken(xmlList);
	}Catch(err){
		printf("error");
	}
}

/**
 *
 * given:
 *  <data>
 *			<name>
 * 					<first>ABC</first>
 *    	</name>
 *  </data>
 *
 *
 */

void test_display3(void){
  CEXCEPTION_T err;
  Tag tag;
	Token *leftAngleBracket   = (Token*)createOperatorToken("<");
	Token *rightAngleBracket  = (Token*)createOperatorToken(">");
	Token *slash              = (Token*)createOperatorToken("/");
  Token *idName             = (Token*)createIdentifierToken("name");
  Token *idFirstName        = (Token*)createIdentifierToken("first");
  Token *idData             = (Token*)createIdentifierToken("data");
  Token *contentName        = (Token*)createStringToken("ABC");
	
	XmlList *xmlList = malloc(sizeof(XmlList));
	
	xmlList = createXmlList();
	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idData);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idName);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idFirstName);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(contentName);
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idFirstName);	
	getToken_ExpectAndReturn(rightAngleBracket);
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idName);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idData);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	// Try{
  xmlList = checkToken();
    
  printf("\n %s", xmlList->head->data);
  do{
    xmlList->head = xmlList->head->child;
    printf("\n %s1", xmlList->head->data);
  }while(xmlList->head->child != NULL);
  // printf("\n %s", xmlList->tail->data);
  // printf("%d", xmlList->length);
 
  // TEST_ASSERT_NOT_EQUAL(xmlList->head, NULL);
  // TEST_ASSERT_NOT_EQUAL(xmlList->tail, NULL);
	// }Catch(err){
		// printf("lol");
	// }
}


/**
 * 
 * given: 
 *  <data> 
 *    <class/> 
 *		<name>ABC</name>                                       
 *    <age>18</age>
 *  </data>
 *
 *
 */

void test_display4(void){
  CEXCEPTION_T err;
  
	Token *leftAngleBracket   = (Token*)createOperatorToken("<");
	Token *rightAngleBracket  = (Token*)createOperatorToken(">");
	Token *slash              = (Token*)createOperatorToken("/");
  Token *idName             = (Token*)createIdentifierToken("name");
  Token *idAge              = (Token*)createIdentifierToken("age");
  Token *idData             = (Token*)createIdentifierToken("data");
  Token *idClass            = (Token*)createIdentifierToken("class");
  Token *contentName        = (Token*)createStringToken("ABC");
  Token *contentAge         = (Token*)createStringToken("18");
  
	XmlList *xmlList = malloc(sizeof(XmlList));
	
	xmlList = createXmlList();
	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idData);	
	getToken_ExpectAndReturn(rightAngleBracket);	
  getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idClass);	
  getToken_ExpectAndReturn(slash);
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idName);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(contentName);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idName);	
	getToken_ExpectAndReturn(rightAngleBracket);	
  getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idAge);	
  getToken_ExpectAndReturn(rightAngleBracket);
  getToken_ExpectAndReturn(contentAge);
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idAge);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idData);	
	getToken_ExpectAndReturn(rightAngleBracket);	

  xmlList = checkToken();
  printf("\n %s", xmlList->head->data);
  xmlList->head = xmlList->head->child;
  printf("\n %s", xmlList->head->data);

  while(xmlList->head->next != NULL){
    xmlList->head = xmlList->head->next;
    printf("\n %s1", xmlList->head->data);
  }
  printf("%s", xmlList->tail->data);
	// }Catch(err){
		// printf("error");
	// }
}

/**
 *
 * given:
 *  <data>
 *    <class/>
 *		<name>
 *			<first>ABC</first>
 *		</name>
 *    <age>18</age>
 *  </data>
 *
 *
 */

void test_display5(void){
  CEXCEPTION_T err;
  Tag tag;
	Token *leftAngleBracket   = (Token*)createOperatorToken("<");
	Token *rightAngleBracket  = (Token*)createOperatorToken(">");
	Token *slash              = (Token*)createOperatorToken("/");
  Token *idName             = (Token*)createIdentifierToken("name");
  Token *idFirst             = (Token*)createIdentifierToken("first");
  Token *idAge              = (Token*)createIdentifierToken("age");
  Token *idData             = (Token*)createIdentifierToken("data");
  Token *idClass            = (Token*)createIdentifierToken("class");
  Token *contentName        = (Token*)createStringToken("ABC");
  Token *contentAge         = (Token*)createIntegerToken(18);
  
	XmlList *xmlList = malloc(sizeof(XmlList));
	
	xmlList = createXmlList();
	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idData);	
	getToken_ExpectAndReturn(rightAngleBracket);	
  getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idClass);	
  getToken_ExpectAndReturn(slash);
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idName);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idFirst);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(contentName);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idFirst);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idName);	
	getToken_ExpectAndReturn(rightAngleBracket);	
  getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idAge);	
  getToken_ExpectAndReturn(rightAngleBracket);
  getToken_ExpectAndReturn(contentAge);
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idAge);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idData);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	Try{
  xmlList = checkToken();
	}Catch(err){
		printf("\n Error: %s",err->errorMsg);
	}
}

/**
 *
 * given:
 *  <data>
 *  //<class/>
 *		<name grade="A" gender="male">
 *			<first>ABC</first>
 *      <last>DEF</last>
 *		</name>
 *    <age>18</age>
 *  </data>
 *
 *
 */

void test_display6(void){
  CEXCEPTION_T err;
  Tag tag;
	Token *leftAngleBracket   = (Token*)createOperatorToken("<");
	Token *rightAngleBracket  = (Token*)createOperatorToken(">");
	Token *slash              = (Token*)createOperatorToken("/");
	Token *equal              = (Token*)createOperatorToken("=");
  Token *idName             = (Token*)createIdentifierToken("name");
  Token *idFirst            = (Token*)createIdentifierToken("first");
  Token *idLast            = (Token*)createIdentifierToken("last");
  Token *idAge              = (Token*)createIdentifierToken("age");
  Token *idData             = (Token*)createIdentifierToken("data");
  Token *idClass            = (Token*)createIdentifierToken("class");
  Token *idGrade            = (Token*)createIdentifierToken("grade");
  Token *idGender           = (Token*)createIdentifierToken("gender");
  Token *contentName        = (Token*)createStringToken("ABC");
  Token *contentLast        = (Token*)createStringToken("DEF");
  Token *contentGrade       = (Token*)createStringToken("\"A\"");
  Token *contentGender      = (Token*)createStringToken("\"male\"");
  Token *contentAge         = (Token*)createStringToken("18");
  
	XmlList *xmlList = malloc(sizeof(XmlList));
	
	xmlList = createXmlList();
	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idData);	
	getToken_ExpectAndReturn(rightAngleBracket);	
  getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idClass);	
  getToken_ExpectAndReturn(slash);
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idName);	
	getToken_ExpectAndReturn(idGrade);	
	getToken_ExpectAndReturn(equal);
	getToken_ExpectAndReturn(contentGrade);
	getToken_ExpectAndReturn(idGender);
	getToken_ExpectAndReturn(equal);
	getToken_ExpectAndReturn(contentGender);
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idFirst);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(contentName);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idFirst);	
	getToken_ExpectAndReturn(rightAngleBracket);	
  getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idLast);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(contentLast);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idLast);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idName);	
	getToken_ExpectAndReturn(rightAngleBracket);	
  getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idAge);	
  getToken_ExpectAndReturn(rightAngleBracket);
  getToken_ExpectAndReturn(contentAge);
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idAge);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idData);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	// Try{
  xmlList = checkToken();
  printf("\n %s", xmlList->head->data);
  do{
    xmlList->head = xmlList->head->child;
    printf("\n %s1", xmlList->head->data);
  }while(xmlList->head->child != NULL);
}

/**
 *
 *                                                    
 *		<name gender = "male"> ABC </name>        
 *                                       
 */
void test_obtaining_attribute(void){
  CEXCEPTION_T err;
  Tag tag;
	Token *leftAngleBracket   = (Token*)createOperatorToken("<");
	Token *rightAngleBracket  = (Token*)createOperatorToken(">");
	Token *slash              = (Token*)createOperatorToken("/");
	Token *equal              = (Token*)createOperatorToken("=");
  Token *idName             = (Token*)createIdentifierToken("name");
  Token *idGender           = (Token*)createIdentifierToken("gender");
  Token *contentName        = (Token*)createStringToken("ABC");
  Token *contentGrade       = (Token*)createStringToken("\"A\"");
  Token *contentGender      = (Token*)createStringToken("\"male\"");
  
	XmlList *xmlList = malloc(sizeof(XmlList));
	
	xmlList = createXmlList();

	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idName);	
	getToken_ExpectAndReturn(idGender);
	getToken_ExpectAndReturn(equal);
	getToken_ExpectAndReturn(contentGender);
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(contentName);		
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idName);	
	getToken_ExpectAndReturn(rightAngleBracket);	
 
  xmlList = checkToken();

  TEST_ASSERT_EQUAL(TOKEN_OPERATOR_TYPE, xmlList->head->attribute->token->type);
  TEST_ASSERT_EQUAL("=", ((OperatorToken*)(xmlList->head->attribute)->token)->symbol);
  TEST_ASSERT_EQUAL(TOKEN_IDENTIFIER_TYPE, ((OperatorToken*)(xmlList->head->attribute)->token)->token[0]->type);
  // TEST_ASSERT_EQUAL(TOKEN_STRING_TYPE, ((OperatorToken*)(xmlList->head->attribute)->token)->token[1]->type);
}

/**
 *
 *                                                    
 *		<name ABC DEF</name>        
 *                                       
 */
void test_error_missing_bracket(void){
	ErrorObject* err;
  Tag tag;
	XmlList *xmlList = malloc(sizeof(XmlList));
	
	xmlList = createXmlList();
	
	
	Token *leftAngleBracket   = (Token*)createOperatorToken("<");
	Token *rightAngleBracket  = (Token*)createOperatorToken(">");
	Token *slash              = (Token*)createOperatorToken("/");
  Token *idName             = (Token*)createIdentifierToken("name");
  Token *contentName        = (Token*)createStringToken("ABC");
  Token *contentName1       = (Token*)createStringToken("DEF");
  
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idName);	
	getToken_ExpectAndReturn(contentName);	
	getToken_ExpectAndReturn(contentName1);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idName);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	Try{
  xmlList = checkToken();
	}Catch(err){
    printf("%s",err->errorMsg);
  }
}

/**
 *
 *                                                    
 *		name> ABC DEF</name>        
 *                                       
 */
void test_error_missing_bracket_at_start(void){
	ErrorObject* err;
  Tag tag;
	XmlList *xmlList = malloc(sizeof(XmlList));
	
	xmlList = createXmlList();
	
	
	Token *leftAngleBracket   = (Token*)createOperatorToken("<");
	Token *rightAngleBracket  = (Token*)createOperatorToken(">");
	Token *slash              = (Token*)createOperatorToken("/");
  Token *idName             = (Token*)createIdentifierToken("name");
  Token *contentName        = (Token*)createStringToken("ABC");
  Token *contentName1       = (Token*)createStringToken("DEF");
  
	getToken_ExpectAndReturn(idName);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(contentName);	
	getToken_ExpectAndReturn(contentName1);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idName);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	Try{
  xmlList = checkToken();
	}Catch(err){
    printf("%s",err->errorMsg);
  }
}

/**
 *
 *                                                    
 *		<name ABC DEF</age>        
 *                                       
 */
void test_error_wrong_tag(void){
	ErrorObject* err;
  Tag tag;
	XmlList *xmlList = malloc(sizeof(XmlList));
	
	xmlList = createXmlList();
	
	
	Token *leftAngleBracket   = (Token*)createOperatorToken("<");
	Token *rightAngleBracket  = (Token*)createOperatorToken(">");
	Token *slash              = (Token*)createOperatorToken("/");
  Token *idName             = (Token*)createIdentifierToken("name");
  Token *idAge              = (Token*)createIdentifierToken("age");
  Token *contentName        = (Token*)createStringToken("ABC");
  Token *contentName1       = (Token*)createStringToken("DEF");
  
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(idName);	
  getToken_ExpectAndReturn(rightAngleBracket);	
	getToken_ExpectAndReturn(contentName);	
	getToken_ExpectAndReturn(contentName1);	
	getToken_ExpectAndReturn(leftAngleBracket);	
	getToken_ExpectAndReturn(slash);	
	getToken_ExpectAndReturn(idAge);	
	getToken_ExpectAndReturn(rightAngleBracket);	
	Try{
  xmlList = checkToken();
	}Catch(err){
    printf("%s",err->errorMsg);
  }
}
