"""
Routes and views for the bottle application.
"""

from bottle import route, view
from datetime import datetime

@route('/')
@route('/home')
@view('index')
def home():
    """Renders the home page."""
    return dict(
        year=datetime.now().year
    )

@route('/contact')
@view('contact')
def contact():
    """Renders the contact page."""
    return dict(
        title='Contact',
        year=datetime.now().year
    )

@route('/about')
@view('about')
def about():
    """Renders the about page."""
    return dict(
        title='About',
        message='Your application description page.',
        year=datetime.now().year
    )

@route('/officers')
@view('officers')
def events():
    return dict(
        title = 'Officers',
        message = 'Our officers.',
        year=datetime.now().year
    )

@route('/math')
@view('math')
def math():
    return dict(
        title = 'Math',
        year=datetime.now().year
    )

@route('/robotics')
@view('robotics')
def robotics():
    return dict(
        title = 'Robotics',
        year=datetime.now().year
    )

@route('/science')
@view('science')
def science():
    return dict(
        title = 'Science',
        year=datetime.now().year
    )