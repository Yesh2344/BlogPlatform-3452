# Blog Platform
A production-ready C++ blog platform with markdown support.

## Installation
1. Clone the repository: `git clone https://github.com/username/BlogPlatform.git`
2. Install dependencies: `cmake . && make`
3. Run the application: `./blog-platform`

## Usage
1. Create a new blog post: `./blog-platform create --title "My First Post" --content "This is my first post."`
2. List all blog posts: `./blog-platform list`
3. View a blog post: `./blog-platform view --id 1`

## API Documentation
### Endpoints
#### GET /posts
Returns a list of all blog posts.

#### GET /posts/:id
Returns a single blog post by ID.

#### POST /posts
Creates a new blog post.

#### PUT /posts/:id
Updates a single blog post by ID.

#### DELETE /posts/:id
Deletes a single blog post by ID.

## Badges
[![Build Status](https://travis-ci.org/username/BlogPlatform.svg?branch=main)](https://travis-ci.org/username/BlogPlatform)
[![Code Coverage](https://codecov.io/gh/username/BlogPlatform/branch/main/graph/badge.svg)](https://codecov.io/gh/username/BlogPlatform)