# DSA Project

## Group Members
1. Sai Prasanna Panda (2020A7PS0080H)
2. Mokshith Naidu Thakkilapati (2020A7PS1885H)
3. Anish Kumar Kallepalli (2020A7PS0282H)

## Description

Our project will be based on the college’s ERP Course Registration system. It will allow students to login using their ID and password, which will be validated using a map of strings. If the username does not exist or the password does not match, the student will be prompted to re-enter their credentials. After successfully logging in, a list of available courses will be displayed along with their class codes, course codes, section, instructor and timings. The student will have the option to search for a particular course using its code. After selecting a course, they will be prompted to confirm their selection after which it will get added to their cart. We will maintain an array of 6 sets, one for each day of the week. The sets will contain entries for the courses in the cart. On adding a course, we will add an entry to the corresponding sets as per the timings of the course. Each entry of the set will contain the starting slot, ending slot and class code (this will help us in checking for clashes later on). After adding the desired courses, the student can go to the checkout page. There, they will have to validate the courses in their cart. If there is a clash, they will be shown the class codes of the clashing sections and asked to resolve it. If there is no clash, they will be given the option to enroll in the courses.

## Features

1. Student Login
2. Course Registration Interface
3. Course Search Option
4. Efficient Addition and Deletion of Courses
5. Course Cart
6. Checking for clashes
