
import pytest
import time
from playwright.sync_api import sync_playwright

@pytest.fixture(scope="module")
def browser():
    with sync_playwright() as p:
        browser = p.chromium.launch(headless=False)
        yield browser
        browser.close()

def test_login(browser):
    page = browser.new_page()
    page.goto("https://main.d2t1pk7fjag8u6.amplifyapp.com/")
    
    page.wait_for_selector("input[name='password']",timeout=5000)
    page.fill("input[name='username']", "olegvragov@mail.ru")
    page.fill("input[name='password']", "!$Aug1987")
    page.click("button[type='submit']")
        
    page.wait_for_selector(".App",timeout=5000)
    element = page.locator(".App")
    assert element.count() > 0, "Login Failed!"
    print("Login Successful!")

    page.close()

def test_AddToCart(browser):
    page = browser.new_page()
    page.goto("https://main.d2t1pk7fjag8u6.amplifyapp.com/")

    page.fill("input[name='username']", "olegvragov@mail.ru")
    page.fill("input[name='password']", "!$Aug1987")
    page.click("button[type='submit']")

    
    time.sleep(10)

    page.close()