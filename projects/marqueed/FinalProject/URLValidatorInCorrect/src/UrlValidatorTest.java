/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import junit.framework.TestCase;





/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
	   // Test 1: Allow All Schemes
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   System.out.println("Manual Testing: Allow All Schemes");
	   System.out.println("---------------------------------");
	   
	   //Scheme Test----------------------------------------------------------------------
	   System.out.println("SCHEME---------------------------");
	   System.out.println("These Should be True");
	   
	   //Test http://
	   System.out.println("http://www.google.com");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.com"));
	   
	   //Test no http://
	   System.out.println("www.google.com");
	   System.out.println("  Result: " + urlVal.isValid("www.google.com"));

		//Test h3tp://
	   System.out.println("h3tp://www.google.com");
	   System.out.println("  Result: " + urlVal.isValid("h3tp://www.google.com"));
	   
	   System.out.println("\nThese Should be False");
	   
	   //Test http:/
	   System.out.println("http:/www.google.com");
	   System.out.println("  Result: " + urlVal.isValid("http:/www.google.com"));
	   
	   //Test ://
	   System.out.println("://www.google.com");
	   System.out.println("  Result: " + urlVal.isValid("://www.google.com"));
	   
	   //Authority Test -------------------------------------------------------------------
	   System.out.println("\nAUTHORITY---------------------------");
	   System.out.println("These Should be True");
	   
	   //Test .au
	   System.out.println("http://www.google.au");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.au"));
	   
	   //Test .es
	   System.out.println("http://www.google.es");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.es"));
	   
	   //Test .mx
	   System.out.println("http://www.google.mx");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.mx"));
	   
	   System.out.println("\nThese Should be False");
	   
	   //Test blank
	   System.out.println("http://");
	   System.out.println("  Result: " + urlVal.isValid("http://"));
	   
	   //Test without .com
	   System.out.println("http://www.google");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google"));
	   
	   //Test numeric values
	   System.out.println("http://1.3.5");
	   System.out.println("  Result: " + urlVal.isValid("http://1.3.5"));
	   
	   //Test illegal character
	   System.out.println("http://www.google*.com");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google*.com"));
	   
	   //Port Test -------------------------------------------------------------------
	   System.out.println("\nPORT--------------------------------");
	   System.out.println("These Should be True");
	   
	   //Test port 80 (2 digits)
	   System.out.println("http://www.google.com:80");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.com:80"));
	   
	   //Test port 800 (3 digits)
	   System.out.println("http://www.google.com:800");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.com:800"));
	   
	   //Test port 8000 (4 digits)
	   System.out.println("http://www.google.com:8000");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.com:8000"));
	   
	   //Test port 8000 (5 digits)
	   System.out.println("http://www.google.com:80000");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.com:80000"));
	   
	   System.out.println("\nThese Should be False");
	   
	    //Test negative numbered port
	   System.out.println("http://www.google.com:-80");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.com:-80"));
	   
	    //Test number + alpha character port
	   System.out.println("http://www.google.com:80E");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.com:80E"));
	   
	   //Test no port
	   System.out.println("http://www.google.com:");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.com:"));
	   
	   //Path Test -------------------------------------------------------------------
	   System.out.println("\nPATH--------------------------------");
	   System.out.println("These Should be True");
	   
	   //Test root
	   System.out.println("http://www.google.com/");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.com/"));
	   
	   //Test root /path
	   System.out.println("http://www.google.com/path");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.com/path"));
	   
	   System.out.println("\nThese Should be False");
	   
	    //Test for missing /
	   System.out.println("http://www.google.compath");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.compath"));
	   
	    //Test for double /
	   System.out.println("http://www.google.com//path");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.com//path"));
	   
	    //Test for spaces before path 
	   System.out.println("http://www.google.com     /path");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.com     path"));
	   
	    //Test for illegal characters 
	   System.out.println("http://www.google.com/^%");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.com/^&"));
	   
	   //Path Options Test -------------------------------------------------------------------
	   System.out.println("\nPATH OPTIONS--------------------------------");
	   System.out.println("These Should be True");
	   
	   //Test 2 level /path/
	   System.out.println("http://www.google.com/path/");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.com/path/"));
	   
	   //Test 2 level /path/path
	   System.out.println("http://www.google.com/path/path");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.com/path/path"));
	   
	    //Test for missing / on 2 level deep
	   System.out.println("http://www.google.com/pathpath");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.com/pathpath"));
	   
	   System.out.println("\nThese Should be False");
	   
	    //Test for double / on 2 level deep
	   System.out.println("http://www.google.com/path//path");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.com/path//path"));
	   
	   
	   //Queries Test -------------------------------------------------------------------
	   System.out.println("\nQUERIES--------------------------------");
	   System.out.println("These Should be True\n");
	   
	   
	    //Test valid query
	   System.out.println("http://www.google.com?query=valid");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.com?query=valid"));
	   
	   //Test multiple query
	   System.out.println("http://www.google.com?query=valid&yes=should");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.com?query=valid&yes=should"));
	   
	   System.out.println("\nThese Should be False");
	   
	   //Test missing after query=
	   System.out.println("http://www.google.com?query=");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.com?query="));
	   
	   //Test missing ?query
	   System.out.println("http://www.google.com=valid");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.com=valid"));
	   
	   //Test missing double ?
	   System.out.println("http://www.google.com??query=valid");
	   System.out.println("  Result: " + urlVal.isValid("http://www.google.com??query=valid"));
   }
   
   
   public void testYourFirstPartition()
   {
		//Scheme Test----------------------------------------------------------------------
		System.out.println("\nScheme Partition--------------------------------");
		UrlValidator validScheme = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		String genericURL = "www.google.com";
		String schemeURL = "http://";
		boolean verify = false;
		
		for(int i = 0; i < testSchemes.length; i++)
		{
			schemeURL = testSchemes[i].item + genericURL;
			System.out.print("\nTesting " + schemeURL);
			
			verify = validScheme.isValid(schemeURL);
			
			if(verify == testSchemes[i].valid)
			{
				System.out.println("  Result: PASS");
			}
			else
			{
				System.out.println("  Result: FAIL, result did not match expected");
			}
		}
		
   }
   
   public void testYourSecondPartition(){
	   //Authority Test----------------------------------------------------------------------
		System.out.println("\nAuthority Partition--------------------------------");
		UrlValidator validAuthority = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		String genericURL = "http://";
		String authorityURL = "http://";
		boolean verify = false;
		
		for(int i = 0; i < testAuthority.length; i++)
		{
			authorityURL = genericURL + testAuthority[i].item;
			System.out.print("\nTesting " + authorityURL);
			
			verify = validAuthority.isValid(authorityURL);
			
			if(verify == testAuthority[i].valid)
			{
				System.out.println("  Result: PASS");
			}
			else
			{
				System.out.println("  Result: FAIL, result did not match expected");
			}
		}
   }
   
   
   public void testYourThirdPartition(){
	   //Port Test----------------------------------------------------------------------
		System.out.println("\nPort Partition--------------------------------");
		UrlValidator validPort = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		String genericURL = "http://www.google.com";
		String portURL = "http://";
		boolean verify = false;
		
		for(int i = 0; i < testPort.length; i++)
		{
			portURL = genericURL + testPort[i].item;
			System.out.print("\nTesting " + portURL);
			
			verify = validPort.isValid(portURL);
			
			if(verify == testPort[i].valid)
			{
				System.out.println("  Result: PASS");
			}
			else
			{
				System.out.println("  Result: FAIL, result did not match expected");
			}
		}
   }
   
   public void testYourFourthPartition(){
	   //Path Test----------------------------------------------------------------------
		System.out.println("\nPath Partition--------------------------------");
		UrlValidator validPath = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		String genericURL = "http://www.google.com";
		String pathURL = "http://";
		boolean verify = false;
		
		for(int i = 0; i < testPath.length; i++)
		{
			pathURL = genericURL + testPath[i].item;
			System.out.print("\nTesting " + pathURL);
			
			verify = validPath.isValid(pathURL);
			
			if(verify == testPath[i].valid)
			{
				System.out.println("  Result: PASS");
			}
			else
			{
				System.out.println("  Result: FAIL, result did not match expected");
			}
		}
   }
   
    public void testYourFifthPartition(){
	   //Path Test----------------------------------------------------------------------
		System.out.println("\nQuery Partition--------------------------------");
		UrlValidator validQuery = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		String genericURL = "http://www.google.com";
		String queryURL = "http://";
		boolean verify = false;
		
		for(int i = 0; i < testQuery.length; i++)
		{
			queryURL = genericURL + testQuery[i].item;
			System.out.print("\nTesting " + queryURL);
			
			verify = validQuery.isValid(queryURL);
			
			if(verify == testQuery[i].valid)
			{
				System.out.println("  Result: PASS");
			}
			else
			{
				System.out.println("  Result: FAIL, result did not match expected");
			}
		}
   }
   
   public void testIsValid()
   {
	   System.out.println("\nRandom Test--------------------------------");
	   int bugCount = 0;
	   int iter = 10000;
	   
	   UrlValidator randomValid = new UrlValidator();
	   
	   String[] notValidUrl = new String[iter];
	   boolean verify = false;
	   boolean expected = true;
	   
	   for(int i = 0; i < iter; i++)
	   {
		   int iterScheme = (int) (Math.random() * testSchemes.length);
		   int iterauthority = (int) (Math.random() * testAuthority.length);
		   int iterport = (int) (Math.random() * testPort.length);
		   int iterpath = (int) (Math.random() * testPath.length);
		   int iterquery = (int) (Math.random() * testQuery.length);
	   
		   String URL = testSchemes[iterScheme].item + testAuthority[iterauthority].item + testPort[iterport].item + testPath[iterpath].item + testQuery[iterquery].item;
		   verify = randomValid.isValid(URL);
		   
		   
		   if(testSchemes[iterScheme].valid == false || testAuthority[iterauthority].valid == false || testPort[iterport].valid == false || testPath[iterpath].valid == false || testQuery[iterquery].valid == false)
		   {
			   expected = false;
		   }
		   
		   if(verify != expected)
		   {
			   notValidUrl[bugCount] = URL;
			   bugCount++;
		   }
	   }
	   
	   
	   System.out.println("\nURLs Where result did not match expected");
	   for(int j = 0; j < notValidUrl.length; j++)
	   {
		   if(notValidUrl[j] != null)
		   {
			   System.out.println(notValidUrl[j]);
		   }
	   }
	   System.out.println("\nBug Count: " + bugCount);
   }
   
  
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */

	ResultPair[] testSchemes = {
		new ResultPair ("http://", true),
		new ResultPair ("https ://", true),
		new ResultPair("ftp://", true),
		new ResultPair("gftp://", false),
		new ResultPair("h3t://", true),
        new ResultPair("3ht://", false),
		new ResultPair("http:/", false),
		new ResultPair("http:", false),
		new ResultPair("http/", false),
		new ResultPair("://", false),
		new ResultPair("18", false),
		new ResultPair("", true)
		};
		
	ResultPair[] testAuthority = {
		new ResultPair("www.google.com", true),
		new ResultPair("www.google", false),
        new ResultPair("go.com", true),
        new ResultPair("go.au", true),
		new ResultPair("go.mx", true),
		new ResultPair("go.es", true),
        new ResultPair("0.0.0.0", true),
        new ResultPair("255.255.255.255", true),
        new ResultPair("256.256.256.256", false),
        new ResultPair("255.com", true),
        new ResultPair("1.2.3.4.5", false),
        new ResultPair("1.2.3.4.", false),
        new ResultPair("1.2.3", false),
        new ResultPair(".1.2.3.4", false),
        new ResultPair("go.a", false),
        new ResultPair("go.a1a", false),
        new ResultPair("go.cc", true),
        new ResultPair("go.1aa", false),
        new ResultPair("aaa.", false),
        new ResultPair(".aaa", false),
        new ResultPair("aaa", false),
        new ResultPair("", false)
		};
		
		ResultPair[] testPort = {
		new ResultPair(":80", true),
		new ResultPair(":65535", true),
		new ResultPair(":0", true),
		new ResultPair("", true),
		new ResultPair(":-1", false),
		new ResultPair(":65636", true),
		new ResultPair(":80e", false),
		new ResultPair(":8e9", false),
		new ResultPair(":65a", false)
		};
		
		ResultPair[] testPath = {
		new ResultPair("/test1", true),
		new ResultPair("/t123", true),
		new ResultPair("/$23", true),
		new ResultPair("/..", false),
		new ResultPair("/../", false),
		new ResultPair("/test1/", true),
		new ResultPair("", true),
		new ResultPair("/test1/file", true),
		new ResultPair("/..//file", false),
		new ResultPair("/test1//file", false)
		};
		
		ResultPair[] testQuery = {
		new ResultPair("?action=view", true),
		new ResultPair("?action=edit&mode=up", true),
		new ResultPair("?:", false),
		new ResultPair("?action=®", false),
		new ResultPair("", true)
		};

}
