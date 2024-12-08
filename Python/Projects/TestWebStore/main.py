
from playwright.sync_api import sync_playwright
import time

def test_website():
    with sync_playwright() as p:
        browser = p.chromium.launch(headless=False)
        context = browser.new_context()
        page = context.new_page()
                   
        page.goto("https://main.d2t1pk7fjag8u6.amplifyapp.com/")

        page.wait_for_selector("input[name='username']", timeout=5000)
        
        with page.expect_response("**") as response_info:
           page.fill("input[name='username']", "olegvragov@mail.ru")
           page.fill("input[name='password']", "!$Aug1987")
           page.click("button[type='submit']")
        
        response = response_info.value
        assert response.status == 200, f"Login Failed: API returned status {response.status}!"
        print("Login Successful: Login API returned 200 status.")        

        
        time.sleep(5)

       

        


if __name__ == "__main__":
   test_website()

   browser.close()
    